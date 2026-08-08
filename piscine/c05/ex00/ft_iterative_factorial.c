/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:38:17 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/28 22:04:21 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ans;

	ans = 1;
	if (nb < 0)
		return (0);
	while (nb >= 1)
	{
		ans *= nb;
		nb--;
	}
	return (ans);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	int	kaijo;
//	kaijo = ft_iterative_factorial(9);
//	printf("9...？ : ");
//	printf("%d\n", kaijo);
//	kaijo = ft_iterative_factorial(0);
//	printf("0...だと...？:");
//	printf("%d\n", kaijo);
//	return 0;
//}
