/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:22:18 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 18:30:33 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	char u[256];
	int	i = 0;
	int j = 0;
	unsigned char c;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	while (i < 256)
	{
		u[i] = 0;
		i++; 
	}
	i = 1;
	while(i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			c = (unsigned char) argv[i][j];
			if(u[c] == 0)
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
