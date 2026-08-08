/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:46:32 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 23:55:43 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;
	char a_ascii;
	char b_ascii;
	char c_ascii;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				if (a != b && b != c && a != c)
				{
					a_ascii = a + '0';
					b_ascii = b + '0';
					c_ascii = c + '0';
					write(1, &a_ascii, 1);
					write(1, &b_ascii, 1);
					write(1, &c_ascii, 1);
				}
				if (!(a == 7 && a == 8 && c == 9))
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++; 
	}
}


int	main(void)
{
	ft_print_comb();
	return (0);
}
