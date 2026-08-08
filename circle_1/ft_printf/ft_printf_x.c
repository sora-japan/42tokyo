/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 21:40:56 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/05/18 22:53:09 by tfujikaw         ###   ########.fr       */
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
		nb /= 16;
	}
	return (count);
}

static void	ft_putnbr(unsigned int nb, char *base, int *check)
{
	if (nb >= 16)
		ft_putnbr(nb / 16, base, check);
	if (*check == -1)
		return ;
	*check = write(1, base + (nb % 16), 1);
}

int	ft_printf_x(unsigned int n, int *check)
{
	int				count;
	unsigned int	nb;
	char			*base;

	if (*check == -1)
		return (-1);
	base = "0123456789abcdef";
	count = 0;
	nb = n;
	ft_putnbr(nb, base, check);
	if (*check == -1)
		return (-1);
	count += ft_digits(nb);
	return (count);
}
