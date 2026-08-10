#!/bin/sh
# 使い方: ./run.sh [BUFFER_SIZE] [ファイル]
B=${1:-42}
F=${2:-t2.txt}
cc -Wall -Wextra -Werror -D BUFFER_SIZE=$B get_next_line.c get_next_line_utils.c driver.c -o p 2>&1 || exit 1
./p "$F"
