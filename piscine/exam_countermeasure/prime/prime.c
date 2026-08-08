/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 10:03:00 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/03 10:14:40 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return 0;
	while (nb / i > i)
	{
		if (nb % i == 0)
			return 0;
		i++;
	}
	return 1;
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_is_prime(13));
	printf("%d\n", ft_is_prime(-10));
	printf("%d\n", ft_is_prime(0));
	return 0;
}
