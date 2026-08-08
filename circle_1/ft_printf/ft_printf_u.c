/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:40:56 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/05/18 22:52:39 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_digits(unsigned int nb)
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

static void	ft_putnbr(unsigned int nb, int *check)
{
	char	c;

	if (nb >= 10)
		ft_putnbr(nb / 10, check);
	if (*check == -1)
		return ;
	c = (nb % 10) + '0';
	*check = write(1, &c, 1);
}

int	ft_printf_u(unsigned int n, int *check)
{
	int				count;
	unsigned int	nb;

	if (*check == -1)
		return (-1);
	count = 0;
	nb = n;
	ft_putnbr(nb, check);
	if (*check == -1)
		return (-1);
	count += ft_digits(nb);
	return (count);
}
