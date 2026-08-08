*This project has been created as part of the 42 curriculum by tfujikaw.*

# Description（説明）

このプロジェクトの目的はシンプルです。
printf()を再実装します。可変長引数の使い方を学びます。

# Instructions (手順)
## 1. コンパイル方法
本プロジェクトはMakefileを用いて管理されています。
makeコマンドを実行することで、ソースファイルをコンパイルし、静的ライブラリlibftprintf.aを生成します。

- make clean
コンパイル時に生成されたオブジェクトファイル（.o）を削除します。

- make fclean
オブジェクトファイル（.o）に加えて、生成された成果物（libftprintf.a）も含めて完全に削除する。

- make re
既存のオブジェクトファイルをすべて削除し、一から再コンパイルを行います。

## 2. 自分のプロジェクトへの組み込み方

自作のプログラムで `ft_printf` を使用したい場合は、以下の手順で行います。

1. ソースコード内でヘッダーファイルをインクルードします。
#include "ft_printf.h"

2. コンパイル時に、生成された libftprintf.a をリンクし、libft.h のパスを指定します。
cc -Wall -Wextra -Werror -I ./libft main.c libftprintf.a

# Resources

## AIの使用について
AIの使用は最小限とし、ピアラーニングを最優先にしました。
AIを使用する際は、「直接的な答えは出さず、段階的なヒントをお願いします」と指示を出しておりました。
最終確認やテストにも使用いたしました。

## 各関数の説明

- ft_printf
cspdiuxX%の変換指定子に対応しているprintfの再実装。
[各変換指定子（書式指定子）の説明]https://coding-with-me.com/c-print/#google_vignette
[printfについて]https://www.sejuku.net/blog/24934

### 各ファイルの説明
- ft_printf_c.c
%c	文字（char）単一の文字を表示します。

- ft_printf_di.c
%d	整数（int）	10進数で整数を表示します。
%i	整数（int）	%d と同じ動作をします。

- ft_printf_p.c
%p	ポインタ メモリアドレスを表示します。

- ft_printf_percent.c
% を表示できます。

- ft_printf_str.c
%s	文字列（char配列）	文字列を表示します。

- ft_printf_u_x.c / ft_printf_x.c
%x / %X	符号なし整数	16進数で整数を表示します（大文字/小文字）。

- ft_printf_u.c
%u	符号なし整数	10進数で符号なし整数を表示します。

- 各ファイル名の最後の文字がそれぞれ対応している変換指定子の名前になっております。
例：ft_printf_c.c の場合 _(アンダーバー)の次文字のcが対応している書式指定子になっています。

# 選択したアルゴリズムとデータ構造（Algorithm & Data Structure）

## 1. アルゴリズム：線形走査（Linear Scan）と条件分岐
フォーマット文字列を先頭から1文字ずつ走査し、変換指定子（％）を検知した時点で適切な出力関数へ処理を振り分ける「パース（解析）アルゴリズム」を採用しています。

## 2. データ構造：スタックメモリ（Stack）と可変長引数リスト（va_list）
引数の数が動的に変化する特性に対応するため、メモリ上の「スタック構造」と、それを順次参照するための「va_list（ポインタデータ構造）」を採用しています。

## 可変長引数とは
私が見ていて、特にわかりやすく感じた記事と動画のURLを載せておきます。
[Qiita]https://qiita.com/subaruf/items/657c67a1809515589a7c
[youtube]https://www.youtube.com/watch?v=Gl6yIw3hTDA

