/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 01:10:18 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/21 14:38:55 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//void	ft_putchar(char c)
//{
//	write(1, &c, 1);
//}
void	ft_putchar(char c);

void	up(int x, int y)
{
	if (x >= 1)
	{
		ft_putchar('A');
	}
	while (x - 1 > 1)
	{
		if (x > 1 || y < 3)
		{
			ft_putchar('B');
		}
		x--;
	}
	if (x >= 2)
	{
		ft_putchar('C');
	}
}

void	under(int x, int y)
{
	if (x >= 1)
	{
		ft_putchar('C');
	}
	while (x - 1 > 1)
	{
		if (x > 1 || y < 3)
		{
			ft_putchar('B');
		}
		x--;
	}
	if (x >= 2)
	{
		ft_putchar('A');
	}
}

void	middloop(int x, int y)
{
	int		i;

	while (y - 1 > 1)
	{
		ft_putchar('B');
		i = x;
		while (i - 1 > 1)
		{
			ft_putchar(' ');
			i--;
		}
		ft_putchar('B');
		ft_putchar('\n');
		y--;
	}
}

void	midd(int x, int y)
{
	if (x >= 3 && y >= 3)
	{
		middloop(x, y);
	}
	else
	{
		while (y - 1 > 1)
		{
			ft_putchar('B');
			ft_putchar('\n');
			y--;
		}
	}
}

void	rush(int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	up(x, y);
	if (y > 1)
	{
		ft_putchar('\n');
		midd(x, y);
		under(x, y);
	}
	ft_putchar('\n');
}

/*
int	main(void)
{
	rush(1, -1);
	return (0);
}
*/
