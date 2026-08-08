/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:48:02 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 20:55:30 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j;
	unsigned char c;
	char u[256];
	if(argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	while (i < 256)
	{
		u[i] = 0;
		i++;
	}
	i = 0;
	while(argv[1][i])
	{
		c = (unsigned char) argv[1][i];
		j = 0;
		while (argv[2][j])
		{
			if (c == argv[2][j] && u[c] == 0)
			{
				write(1, &c, 1);
				u[c] = 1;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;   
}
