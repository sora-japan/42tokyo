/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:40:56 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/05/18 22:22:15 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_digits(long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

static void	ft_putnbr(long nb, int *check)
{
	char	c;

	if (nb >= 10)
		ft_putnbr(nb / 10, check);
	if (*check == -1)
		return ;
	c = (nb % 10) + '0';
	*check = write(1, &c, 1);
}

int	ft_printf_di(int n, int *check)
{
	int		count;
	long	nb;

	if (*check == -1)
		return (-1);
	count = 0;
	nb = n;
	if (nb < 0)
	{
		*check = write(1, "-", 1);
		if (*check == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	ft_putnbr(nb, check);
	if (*check == -1)
		return (-1);
	count += ft_digits(nb);
	return (count);
}
