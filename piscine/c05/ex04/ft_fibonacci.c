/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:29:13 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 23:11:09 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

#include <stdio.h>

int	main(void)
{
	printf("0番目：%d\n", ft_fibonacci(0));
	printf("8番目：%d\n", ft_fibonacci(8));
	printf("７番目：%d\n", ft_fibonacci(7));
	printf("１０番目：%d\n", ft_fibonacci(10));
	return (0);
}
