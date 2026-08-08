/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moji3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 15:39:12 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/05 18:01:17 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	used[256];
	int	i;
	int	j;

	i = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	while (i < 256)
	{
		used[i] = 0;
		i++;
	}
	j = 0;
	while (argv[1][j])
	{
		unsigned char c = (unsigned char) argv[1][j];
		if (used[c] == 0)
		{
			write(1, &c, 1);
			used[c] = 1;
		}
		j++;
	}
	j = 0;
	while (argv[2][j])
	{
		unsigned char c = (unsigned char) argv[2][j];
		if (used[c] == 0)
		{
			write(1, "\n", 1);
			used[c] = 1;
		}
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
