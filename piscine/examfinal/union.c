/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 04:51:49 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 05:07:07 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j;
	char s[256];
	unsigned char c;

	if (argc != 3)
	{
		write (1, "\n", 1);
		return 0;
	}
	while (i < 256)
	{
		s[i] = 0;
		i++;
	}
	i = 1;
	while (i < 3)
	{
		j = 0;
		while (argv[i][j])
		{
			c = (unsigned char) argv[i][j];
			if (s[c] == 0)
			{
				write(1, &c, 1);
				s[c] = 1;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
