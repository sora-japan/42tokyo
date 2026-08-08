/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:20:25 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/08 19:36:22 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

//#include <unistd.h>
//
//void	putnbr(int	nb)
//{
//	char	c;
//	if (nb == -2147483648)
//	{
//		write(1, "-2147483648", 11);
//		return ;
//	}
//	if (nb < 0)
//	{
//		nb = -nb;
//		write(1, "-", 1);
//	}
//	if (nb >= 10)
//		putnbr(nb / 10);
//	c = (nb % 10) + '0';
//	write(1, &c, 1);
//}
//
//int	main(void)
//{
//	//int	tab[1337];
//	//ft_foreach(tab, 1337, &putnbr);
//	int	tab[5] = {1, 2, 3, 4, 5};
//	ft_foreach(tab, 5, &putnbr);	
//	return 0;
//}
