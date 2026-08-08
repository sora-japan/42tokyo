/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 21:06:37 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 22:37:34 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	char	c;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	while (argv[1][i])
	{
		c = argv[1][i];
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
		{
			c = 'z' - (c - 'a');
			write(1, &c, 1);
		}
		else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			c = 'Z' - (c - 'A');
			write(1, &c, 1);
		}
		else
			write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
