/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:54:30 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/28 15:56:29 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putnbr(int n)
{
	char	c;
	char	str[2];
	if(n < 10)
	{
		c = 10 + '0';
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	else if(n >= 11 && n <= 99)	
	{
		str[0] = (n / 10) + '0';
		str[1] = (n % 10) + '0';
		write (1, &str[0], 1);
		write (1, &str[1], 1);
		write(1, "\n", 1);	
	}
	else if (n == 100)
	{
		write(1, "100", 100);
		write(1, "\n", 1);
	}
	return ;
}

int	main(void)
{
	int	i;

	i = 1;
	while(i <= 100)
	{
		if(i % 3 == 0 && !(i % 3 == 0 && i % 5 == 0))
			write(1, "bazz\n", 5);
		else if(i % 5 == 0 && !(i % 3 == 0 && i % 5 == 0))
			write(1, "fizz\n", 5);
		else if(i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbazz\n", 9);
		else
			putnbr(i);
		i++;
	}
	return 0;
}
