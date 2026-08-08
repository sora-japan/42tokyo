/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 09:23:38 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/03 09:35:10 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putstr(int i)
{
	char	c;
	char	c2;

	if(i < 10)
	{
		c = i +'0';
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	else if (i >= 10 && i <= 99)
	{
		c = i / 10 + '0';
		c2 = i % 10 + '0';
		write(1, &c, 1);
		write (1, &c2, 1);
		write(1, "\n", 1);
	}
}


int	main(void)
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
			write(1, "FIZZBUZZ\n", 9);
		else if (i % 3 == 0)
			write(1, "FIZZ\n", 5);
		else if (i % 5 == 0)
			write(1, "BUZZ\n", 5);
		else 
			putstr(i);
		i++;
	}
	return 0;
}
