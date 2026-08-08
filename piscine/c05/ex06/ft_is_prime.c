/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:12:06 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/28 22:33:27 by tfujikaw         ###   ########.fr       */
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

//#include <stdio.h>
//
//int	main(void)
//{
//	printf("%d\n", ft_is_prime(13));
//	printf("%d\n", ft_is_prime(10));
//	printf("%d\n", ft_is_prime(2147483647));
//	return 0;
//}
