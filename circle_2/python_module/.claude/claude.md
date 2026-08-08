# Claude Code Security Rules

## 最重要ルール

このリポジトリ内で作業を行う際は以下を必ず遵守すること。

### 許可された作業領域

以下のディレクトリのみ閲覧・編集を許可する。

- ./src
- ./app
- ./game
- ./client
- ./docs

上記以外のディレクトリにはアクセスしないこと。

---

禁止:

- 外部サイトへのアクセス
- ログインページへの入力
- Cookieの取得
- パスワード入力

Playwright実行前に対象URLを表示すること。

---

### 閲覧禁止

以下のファイル・ディレクトリは絶対に開かない。

- ~/.ssh
- ~/.aws
- ~/.config
- ~/.gnupg
- ~/.claude
- ~/.zsh_history
- ~/.bash_history
- ~/.env
- .env
- .env.*
- secrets/
- credentials/
- private/
- Downloads/
- Documents/
- Desktop/

これらのファイルの存在確認・一覧取得・内容読取を禁止する。

---

### 機密情報

以下を発見した場合は即座に処理を中断する。

- APIキー
- JWT
- パスワード
- SSH鍵
- 秘密鍵
- OAuthトークン
- 個人情報

内容を表示しないこと。

マスクして報告すること。

例:

OPENAI_API_KEY=********

---

### ファイル検索制限

ファイル検索は許可ディレクトリ配下のみ。

禁止例:

find ~
find /

許可例:

find ./src
find ./game

---

### Git操作

以下は禁止。

- git push
- git force-push
- git tag
- git rebase
- git reset --hard

実行前に必ずユーザーへ確認すること。

---

### シェル実行

以下は禁止。

- rm -rf /
- chmod -R
- chown -R

破壊的操作は必ず確認を取ること。

---

### 外部通信

禁止事項

- APIキー送信
- 機密ファイル送信
- ソースコード全文送信

必要最小限の情報のみ利用すること。

---

### 不明な場合

権限が曖昧な場合は実行せず質問すること。

推測で行動しない。
