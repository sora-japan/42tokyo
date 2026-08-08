/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 04:39:36 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 18:53:15 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void putnbr(int nb)
{
	char	c;

	if (nb <= 9)
	{
		c = nb + '0';
		write (1, &c, 1);
		write(1, "\n", 1);
	}
	else if (nb >= 10 && nb <= 99)
	{
		c = (nb / 10) + '0';
		write(1, &c, 1);
		c = (nb % 10) + '0';
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	else if (nb == 100)
	{
		write(1, "100", 3);
		write(1, "\n", 1);
	}
}

int	main(void)
{
	int	nb;

	nb = 1;
	while (nb <= 100)
	{
		if (nb % 3 == 0 && !(nb % 5 == 0))
			putstr("fizz");
		else if (nb % 5 == 0 && !(nb % 3 == 0))
			putstr("buzz");
		else if (nb % 3 == 0 && nb % 5 ==0)
			putstr("fizzbuzz");
		else
			putnbr(nb);
		nb++;
	}
}
