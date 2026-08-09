
#include "get_next_line.h"
#include <fcntl.h> // open 関数の定義
#include <malloc.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test.txt", O_RDONLY);
	// fd = 0;
	line = get_next_line(fd);
	if (line == NULL)
	{
		printf("%s\n", line);
		return (0);
	}
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (LINE_DELIMITER != '\n' && line[i] == LINE_DELIMITER)
			{
				write(1, &line[i], 1);
				write(1, "<LB>\n", 5);
				i++;
				continue ;
			}
			if (LINE_DELIMITER != '\n' && line[i] == '\n')
			{
				write(1, "<\\n>", 4);
				i++;
				continue ;
			}
			else
				write(1, &line[i], 1);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	// write(1, "\n", 1);
	close(fd);
	return (0);
}
/*
** コンパイル:
**   cc -Wall -Wextra -Werror -Wextra \
		-D BUFFER_SIZE=4 get_next_line.c get_next_line_utils.c test.c
*/

/*
	xxd test.txt
	./a.out | xxd
	diff <(./a.out) test.txt
*/

// fd = 0 : ユーザー入力の時
//
// printf "hello\nworld\nfoo\n" | ./a.out

//	./a.out < test.txt
//		このとき、fd = 0として読んでいるはずの./a.outの中で、read関数の第一引数が 0(標準入力)になっているのを確認する方法
//		strace -e trace=read ./a.out < test.txt 2>&1 | grep "^read(0"
//			↔逆に通常のfdのときのチェック方法:
//			strace -e trace=openat,read ./a.out 2>&1 | grep -E "openat|read"
//			strace -P test.txt -e trace=openat,read ./a.out
//
//
//	差分を確認
//	diff <(./a.out < test.txt) test.txt
