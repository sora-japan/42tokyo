/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:16:16 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/29 04:53:59 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ans;

	ans = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		ans *= nb;
		power--;
	}
	return (ans);
}

//#include <stdio.h>
//int	main(void)
//{
//	printf("3の5乗:");
//	printf("%d\n", ft_iterative_power(3, 5));
//	printf("0の5乗:");
//	printf("%d\n", ft_iterative_power(0, 5));
//	printf("3の0乗:");
//	printf("%d\n", ft_iterative_power(3, 0));
//	printf("0の0乗:");
//	printf("%d\n", ft_iterative_power(0, 0));
//	return 0;
//}
