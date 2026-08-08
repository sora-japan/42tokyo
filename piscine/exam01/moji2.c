/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moji2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 05:46:59 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/05 05:57:06 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	used[256];
	unsigned char c;
	int	i;
	int j;
	int k;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while(i < 256)
	{
		used[i] = 0;
		i++;
	}
	j = 0;
	while (argv[1][j])
	{
		k = 0;
		while (argv[2][k])
		{
			(unsigned char)c = argv[2][k];
			if (used[] == 0)
			{
			}
			k++;
		}
		j++;
	}

	return (0);
}
