/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 02:52:04 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/08/07 05:06:57 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// テスト用にプロトタイプ宣言
char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	// 1. テスト用のファイルを開く
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("ファイルを開けませんでした (test.txt を作成してください)");
		return (1);
	}
	printf("--- get_next_line テスト開始 (BUFFER_SIZE: %d) ---\n", BUFFER_SIZE);
	// 2. ループで1行ずつ読み込む
	line_count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		// get_next_line は改行コードを含んで返すので、%s の後ろに \n は不要です
		printf("Line [%02d]: %s", line_count, line);
		// 読み終わったメモリは必ず free する
		free(line);
		line_count++;
	}
	printf("\n--- テスト終了 (ファイルの末尾に到達しました) ---\n");
	// 3. ファイルを閉じる
	close(fd);
	return (0);
}
