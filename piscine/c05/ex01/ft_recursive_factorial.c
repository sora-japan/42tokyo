/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:58:43 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/31 22:27:18 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

//#include <stdio.h>
//
//int	main(void)
//{
//	printf("%d\n", ft_recursive_factorial(5));
//	printf("%d\n", ft_recursive_factorial(1));
//	printf("%d\n", ft_recursive_factorial(0));
//	return 0;
//}
