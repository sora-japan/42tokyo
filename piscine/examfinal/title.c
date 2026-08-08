/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 11:03:42 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 15:20:42 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;
	if (argc < 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && (argv[i][j] == ' ' || argv[i][j] == '\t'))
			{
				write(1, &argv[i][j], 1);
				j++;
			}
			if (argv[i][j])
			{
				if(argv[i][j] >= 'a' && argv[i][j] <= 'z')// 小文字だけを大文字へ
					argv[i][j] -= 32; 
				write(1, &argv[i][j], 1);
				j++;　
				while (argv[i][j] && !(argv[i][j] == ' ' || argv[i][j] == '\t'))
				{
					write(1, &argv[i][j], 1);
					j++;
				}
			}
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
