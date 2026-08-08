/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bazzfizz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:57:32 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/08 19:11:34 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int i)
{
	char	c;

	if (i < 10)
	{
		c = i +'0';
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	else if (i >= 10 && i <= 99)
	{
		c = (i / 10) + '0';
		write(1, &c, 1);
		c = (i % 10) + '0';
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	else if ( i == 100)
	{
		write(1, "100", 1);
		write(1, "\n", 1);
		write(1, "\n", 1);
	}
}


int main()
{
	int	i = 1;

	while (i <= 100)
	{
		if ((i % 4 == 0) && (i % 7 == 0))
		{
			write(1, "buzzfizz", 8);	
			write(1, "\n", 1);
		}
		else if (i % 4 ==0)
		{
			write (1, "buzz", 4);
			write(1, "\n", 1);
		}
		else if (i % 7 == 0)
		{
			write(1, "fizz", 4);	
			write(1, "\n", 1);
		}
		else
			ft_putnbr(i);
		i++;
	}
}
