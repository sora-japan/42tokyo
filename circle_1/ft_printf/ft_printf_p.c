/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 01:40:26 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/05/18 22:53:21 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_digits(unsigned long nb)
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

static void	ft_putnbr(unsigned long nb, char *base, int *check)
{
	if (nb >= 16)
		ft_putnbr(nb / 16, base, check);
	if (*check == -1)
		return ;
	*check = write(1, base + (nb % 16), 1);
}

int	ft_printf_p(void *p, int *check)
{
	int				count;
	unsigned long	nb;
	char			*base;

	if (*check == -1)
		return (-1);
	if (!p)
	{
		*check = write(1, "(nil)", 5);
		if (*check == -1)
			return (-1);
		return (5);
	}
	base = "0123456789abcdef";
	count = 0;
	nb = (unsigned long)p;
	*check = write(1, "0x", 2);
	if (*check == -1)
		return (-1);
	count = 2;
	ft_putnbr(nb, base, check);
	if (*check == -1)
		return (-1);
	count += ft_digits(nb);
	return (count);
}
