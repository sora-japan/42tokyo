/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:23:39 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 15:32:31 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check_base(char *base)
{
	int		i;
	char	used[256];
	int		len;

	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	i = 0;
	while (i < 256)
		used[i++] = 0;
	i = 0;
	while (base[i])
	{
		if ((base[i] <= ' ') || (base[i] > '~'))
			return (0);
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		if (used[(unsigned char) base[i]])
			return (0);
		used[(unsigned char) base[i]] = 1;
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		n;
	long	nbrr;

	if (!check_base(base))
		return ;
	n = ft_strlen(base);
	nbrr = nbr;
	if (nbrr < 0)
	{
		write(1, "-", 1);
		nbrr = -nbrr;
	}
	if (nbrr >= n)
		ft_putnbr_base(nbrr / n, base);
	write(1, base + (nbrr % n), 1);
}

int main(void)
{
	int		nbr = 12345;
	char	*base;

	base = "0123456789";
	ft_putnbr_base(nbr, base);
	return (0);
}
