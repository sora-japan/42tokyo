/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 23:05:11 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 23:11:32 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_fibonacci(int index)
{
	if (index < 0)
		return -1;
	if (index == 0)
		return 0;
	if (index == 1)
		return 1;
	return ft_fibonacci(index - 1) + ft_fibonacci(index -2);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_fibonacci(10));
	return 0;
}
