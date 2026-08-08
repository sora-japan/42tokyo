/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saiki.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:59:26 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 23:04:01 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_recursive_factorial(int nb)
{
	if (nb < 1)
		return 0;
	if (nb == 1)
		return 1;
	return nb * ft_recursive_factorial(nb - 1);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_recursive_factorial(3));
	return 0;
}
