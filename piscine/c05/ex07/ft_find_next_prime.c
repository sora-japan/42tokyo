/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:32:38 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/28 22:41:46 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	cal;

	if (nb <= 1)
		return (0);
	cal = 2;
	while (cal < nb / cal)
	{
		if (nb % cal == 0)
			return (0);
		cal++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
//#include <stdio.h>
//
//int	main(void)
//{
//	printf("%d\n", ft_find_next_prime(13));
//	printf("%d\n", ft_find_next_prime(20));
//	printf("%d\n", ft_find_next_prime(1));
//	printf("%d\n", ft_find_next_prime(2147483647));
//	return 0;
//}
