# get_next_line — 評価対策ノート

> このファイルは自分用の学習メモです。提出物ではありません（subject が要求するのは `get_next_line.c` / `get_next_line_utils.c` / `get_next_line.h` と `README.md` のみ）。

---

## 0. 現状サマリ

| 項目 | 状態 |
| --- | --- |
| mandatory part | 実装済み・francinette 全項目パス |
| bonus part | **未実装**（`_bonus` ファイル無し／複数 fd 非対応） |
| Norm | 提出3ファイルは `OK!`。`main.c` にエラーあり（提出対象外） |
| メモリリーク | `leaks` で 0。malloc 全箇所を1つずつ失敗させても 0 |

**bonus の要件（やらないが、聞かれたら答えられるように）**
1. `static` 変数を **1つだけ** で実装すること
2. 複数の fd を同時に扱えること（fd 3 → 4 → 5 → 3 → 4 … と交互に読んでも各 fd の読み取り位置を見失わない）
3. ファイル名は `get_next_line_bonus.c` / `get_next_line_bonus.h` / `get_next_line_utils_bonus.c`

→ 現状は 1 は満たしている（`static t_save s` 1つ）が、2 を満たしていないので bonus としては不成立。

---

## 1. 全体像

### ファイルと関数の対応

| ファイル | 関数 | 種別 |
| --- | --- | --- |
| `get_next_line.h` | `t_save` 型定義・`BUFFER_SIZE` 既定値・プロトタイプ | — |
| `get_next_line.c` | `grow` / `append` / `fill_save` | `static`（外から見えない） |
| | `get_next_line` | 公開 |
| `get_next_line_utils.c` | `nl_pos` / `reset_save` / `str_line` / `consume` | 公開（別ファイルから呼ぶため） |

Norm の「1ファイル5関数まで」に対して 4関数 / 4関数 なので余裕がある。

### データ構造

```c
typedef struct s_save
{
	char	*data;	/* 持ち越しバイト列（\0 終端ではない） */
	size_t	len;	/* いま入っている有効バイト数 */
	size_t	cap;	/* malloc で確保済みのバイト数 */
}	t_save;
```

**「文字列」ではなく「バイト列＋長さ＋容量」で持っている**のがこの実装の肝。理由は3つ:

1. **長さを数え直さなくていい** — 文字列だと連結のたびに先頭から `\0` を探す必要がある。
2. **`\0` が混ざっても壊れない** — 途中に `\0` があっても `\n` を見失わない（バイナリは subject 上は未定義動作だが、壊れないに越したことはない）。
3. **`cap` を分離できる** — 「必要な量」と「確保済みの量」を分けることで、**容量が足りているときは malloc を一切しない**という最適化ができる。これが性能上の要。

---

## 2. コード読み合わせ

### `get_next_line()` — 司令塔

```c
char	*get_next_line(int fd)
{
	static t_save	s;      // ← 唯一の static。呼び出しをまたいで持ち越し分を保持
	char			*line;
	size_t			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);                 // ① 引数の検証
	if (!fill_save(fd, &s) || s.len == 0)
	{
		reset_save(&s);                // ② エラー or 読むものが無い → 全解放して NULL
		return (NULL);
	}
	line = str_line(&s, &len);         // ③ 先頭〜最初の \n までを切り出す
	if (!line)
	{
		reset_save(&s);                // ④ malloc 失敗も同じ扱い
		return (NULL);
	}
	consume(&s, len);                  // ⑤ 返した分をバッファから捨てる（malloc しない）
	return (line);
}
```

**ポイント: `NULL` を返す経路がすべて `reset_save()` を通っている。** これによって「NULL が返った時点で内部メモリはゼロ」が保証される。テスターの `_NULL_CHECK`（malloc をわざと失敗させてリークを見る）を通せた理由がこれ。

### `fill_save()` — 必要な分だけ読む

```c
static int	fill_save(int fd, t_save *s)
{
	if (nl_pos(s, 0) >= 0)
		return (1);                    // ★ 持ち越しに既に \n がある → read を1回も呼ばない
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (0);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (free(buf), 0);     // read エラー
		start = s->len;                // ★ 追記前の位置を覚える
		if (!append(s, buf, (size_t)n))
			return (free(buf), 0);     // malloc 失敗
		if (nl_pos(s, start) >= 0)     // ★ 新しく読んだ範囲だけ \n を探す
			break ;
	}
	free(buf);
	return (1);
}
```

- `n == 0`（EOF）のときは `append` が何もせず、`nl_pos(s, start)` も `-1`、`while (n > 0)` が偽になってループを抜ける。
- 戻り値は「成功/失敗」の `int`。読めた中身は `s` に入っている。

### `grow()` — 容量を2倍ずつ広げる

```c
static int	grow(t_save *s, size_t need)
{
	if (need <= s->cap)
		return (1);                    // ★ 足りていれば malloc しない
	cap = s->cap;
	if (cap == 0)
		cap = BUFFER_SIZE + 1;         // 初回は read 1回分が入るサイズ
	while (cap < need)
		cap *= 2;                      // 足りるまで倍々
	new = malloc(cap);
	if (!new)
		return (0);
	/* 既存の len バイトをコピー */
	free(s->data);
	s->data = new;
	s->cap = cap;
	return (1);
}
```

### `consume()` — 返した分を前へ詰める（malloc しない）

```c
void	consume(t_save *s, size_t len)
{
	i = 0;
	while (len + i < s->len)
		s->data[i] = s->data[len + i], i++;   /* 実際は while ブロックで記述 */
	s->len = i;
}
```

`memmove` 相当を自前で書いたもの。**確保済みバッファをそのまま再利用する**ので、行を返すたびの malloc/free が発生しない。

### `nl_pos()` / `str_line()` / `reset_save()`

- `nl_pos(s, from)` — `from` 以降で最初の `\n` の位置。無ければ `-1`。`from` を渡せるのは「新しく読んだ範囲だけ走査する」ため。
- `str_line(s, &len)` — 先頭から最初の `\n`（含む）までを `\0` 終端付きでコピー。`\n` が無ければ末尾まで（＝最終行）。切り出した長さを `len` に書き戻す。**確保サイズはちょうど `len + 1`**（テスターはここも見ている）。
- `reset_save(s)` — `free(data)` して `data`/`len`/`cap` を 0 に戻す。

---

## 3. 動作トレース（口頭説明用）

**ファイル `"ab\ncd"`（5バイト、末尾に改行なし）を `BUFFER_SIZE=3` で読む場合**

| | 処理 | `data` | `len` | `cap` | 戻り値 |
| --- | --- | --- | --- | --- | --- |
| 開始 | | `NULL` | 0 | 0 | |
| **1回目** | `read` → `"ab\n"`、`grow` で `cap=4` 確保、追記 | `ab\n` | 3 | 4 | |
| | `\n` を発見 → 読むのをやめる | | | | |
| | `str_line` → `"ab\n"` を新規確保 | | | | `"ab\n"` |
| | `consume(3)` → 残り0バイト | `ab\n`（無効） | 0 | 4 | |
| **2回目** | `read` → `"cd"`、**`cap=4` で足りるので malloc なし** | `cd` | 2 | 4 | |
| | `\n` 無し → もう一度 `read` → `0`(EOF) | `cd` | 2 | 4 | |
| | `str_line` → `"cd"`（`\n` 無しの最終行） | | | | `"cd"` |
| | `consume(2)` | | 0 | 4 | |
| **3回目** | `read` → `0`、`len == 0` | | | | |
| | `reset_save` で解放 | `NULL` | 0 | 0 | `NULL` |

malloc 回数: 1回目=3（buf・バッファ・返す行）、2回目=2（buf・返す行）、3回目=1（buf）。`buf` は毎回 `free` している。

---

## 4. 想定質問と答え

### Q. `static` 変数とは？なぜ必要？

関数を抜けても値が消えず、プログラム終了まで生き続ける変数。初期化は1度だけ（明示しなければゼロ初期化）。
`get_next_line` は「改行が来るまで読む」ので、`read` が改行を追い越して読んでしまった余りが必ず発生する。その**余りを次の呼び出しに引き継ぐ**ために必要。`static` が無いと、次の呼び出しで余りを捨ててしまい、行が欠ける。

**グローバル変数との違い**: 生存期間は同じだが、スコープが関数内に限定されるので他から触れない。subject の「グローバル変数禁止」を満たしつつ状態を保てる。

### Q. `BUFFER_SIZE` が 1 でも 10000000 でも動くのはなぜ？

`BUFFER_SIZE` は **`read` を1回呼ぶときの読み取り単位**にすぎず、**行の長さとは無関係**だから。
- 小さい場合 → `\n` が来るまでループが回数を増やして対応する。
- 大きい場合 → 1回の `read` で複数行ぶん読めてしまうが、余りは `data` に持ち越して次の呼び出しで使う。

つまり「読み取り単位」と「行」を完全に分離し、その差を持ち越しバッファが吸収している。

### Q. なぜ容量を2倍ずつ広げるのか？（**最重要**）

素朴な実装（読むたびに `save` 全体を malloc し直して連結）だと、長さ `N` の行を読む間に

- malloc 回数: `N / BUFFER_SIZE` 回
- コピー総量: `BUFFER_SIZE + 2·BUFFER_SIZE + … + N` ≒ **`O(N² / BUFFER_SIZE)`**

となり、行が長く `BUFFER_SIZE` が小さいほど爆発的に遅くなる。

容量を2倍にすると拡張は `log₂(N)` 回しか起きず、コピー総量は `1 + 2 + 4 + … + N < 2N` で **`O(N)`** に収まる（等比級数）。1バイト追記あたりのコストが平均で定数になる ＝ **償却計算量が O(1)**。`std::vector` などが使っている定番の手法。

**実測（20000バイトの1行）**

| 方式 | malloc 回数 |
| --- | --- |
| 毎回連結し直す（`BUFFER_SIZE=10`） | 約 2000 |
| 本実装（`BUFFER_SIZE=10`） | 15 |
| 本実装（`BUFFER_SIZE=1`） | 18 |

### Q. `read` が `-1` を返したらどうする？

`fill_save` が失敗を返し、`get_next_line` が `reset_save` で持ち越しを解放して `NULL` を返す。エラー時に中途半端なデータを返さない／メモリを残さないため。

### Q. 末尾が改行で終わらないファイルは？

`str_line` は `\n` が見つからなければ末尾までを返すので、最後の行は `\n` なしで返る。その次の呼び出しでは `len == 0` になり `NULL`。subject の指定どおり。

### Q. なぜ `lseek` が禁止なのか？

`lseek` は seek 可能なファイルにしか使えない。パイプ・ソケット・端末（標準入力）では失敗する。「読みすぎた分を巻き戻す」実装に頼らず、**自前でバッファに持ち越す**設計を学ばせるための制約。

### Q. 返した行の `free` は誰の責任？

呼び出し側。`get_next_line` は毎回 malloc した新しい文字列を返すので、使い終わったら呼び出し側が `free` する。内部の持ち越しバッファは `get_next_line` が自分で管理し、`NULL` を返すときに解放する。

### Q. 複数の fd を交互に読むとどうなる？

`static` が1つしかないので、**内容が混ざって壊れる**（実測済み）。これは mandatory の仕様上は問題なく、まさに bonus part の課題。対応するなら fd をキーにした配列（`t_save s[OPEN_MAX]`）か連結リストにする（→ §6）。

### Q. `cap` の初期値が `BUFFER_SIZE + 1` なのはなぜ？

`read` 1回ぶんが必ず入るサイズにするため。厳密には `BUFFER_SIZE` ちょうどでも足りるので、`+1` は余裕を持たせているだけ（`\0` を置く実装に変えても壊れないようにする保険）。

### Q. `nl_pos` の戻り値が `ssize_t` なのはなぜ？

「見つからなかった」を `-1` で表すため。`size_t` は符号なしなので `-1` が巨大な正の値になってしまう。

---

## 4.5 AI の利用について（聞かれたら）

- 最初の設計・実装は自分で行った。
- その後テスターで見つかった2点 — ① malloc 失敗時に持ち越しバッファが解放されずリーク、② 長い行を小さい `BUFFER_SIZE` で読むと malloc とコピーが二乗に増えてタイムアウト — の原因切り分けと、2倍拡張方式への書き換えに AI を利用した。
- 採用した設計の理由は §4 のとおり自分の言葉で説明できる状態にしてある。
- README にも同じ内容を明記済み。

---

## 5. デモ用コマンド

```sh
# ふつうにコンパイル
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

# -D なしでもコンパイルできる（ヘッダの既定値 42 が使われる）
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c

# BUFFER_SIZE を極端に変えても同じ出力になることを見せる
for B in 1 2 9999 10000000; do cc -Wall -Wextra -Werror -D BUFFER_SIZE=$B get_next_line.c get_next_line_utils.c main.c -o gnl && ./gnl; done

# 標準入力から読める
printf 'aa\nbb\ncc' | ./gnl_stdin

# Norm
norminette get_next_line.c get_next_line_utils.c get_next_line.h

# リーク（macOS）
leaks --atExit -- ./gnl
```

**用意しておくべきテストファイル**: 空ファイル / 1文字だけ / 改行のみ / 改行で終わらない / 改行が連続する / 非常に長い1行 / 存在しないファイル / ディレクトリ / `fd = -1`

---

## 6. 「軽微な修正」を求められたときの備え

subject Chapter VII に、評価中に小さな変更を依頼されることがあると書かれている。よくあるお題と対応箇所:

| お題 | 変更点 |
| --- | --- |
| 返す行から `\n` を取り除く | `str_line` で `*len` を決めた後、`\n` の分だけコピー長を1減らす（`consume` に渡す長さは変えない） |
| 空行（`"\n"` だけの行）をスキップする | `get_next_line` の最後で、切り出した行が `"\n"` だけなら `free` してもう一度処理を回す（ループ化） |
| 行番号も返せるようにする | `t_save` に `size_t nline` を追加してインクリメント、取得用の関数を足す |
| 読み込み済みバイト数を数える | `t_save` にカウンタを追加し `append` で加算 |
| **複数 fd 対応（bonus 相当）** | `static t_save s;` を `static t_save s[1024];` にして、`&s[fd]` を各関数に渡すだけ。`fd < 1024` のチェックを追加。※ `static` は1つのままなので bonus 要件も満たせる |

複数 fd 対応の差分イメージ:

```c
char	*get_next_line(int fd)
{
	static t_save	s[1024];        // ← 配列にする（static は変わらず1つ）

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!fill_save(fd, &s[fd]) || s[fd].len == 0)
	{
		reset_save(&s[fd]);
		return (NULL);
	}
	/* 以下 &s[fd] に置き換えるだけ */
}
```

---

## 7. 詰まりやすいポイントの再確認

- `read` の戻り値は `ssize_t`。`-1`（エラー）/ `0`（EOF）/ 正の値（読めたバイト数）の3通りを必ず区別する。読めたバイト数は `BUFFER_SIZE` より少ないこともある（パイプや端末では普通に起きる）。
- `data` は `\0` 終端していない。長さは必ず `len` で判断する。`strlen` 的な発想で触ると壊れる。
- `consume` の後も `cap` は減らない（＝メモリは確保したまま）。これは意図的な再利用。「解放し忘れでは？」と聞かれたら「次の行で再利用するため。`NULL` を返すときに `reset_save` で必ず解放している」と答える。
- `get_next_line` が `NULL` を返す前に必ず `reset_save` が呼ばれる、という不変条件が全体の安全性を支えている。
