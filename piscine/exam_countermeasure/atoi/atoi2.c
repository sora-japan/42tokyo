/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:31:53 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 21:44:32 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
	int	si;
	int re;
	si = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;

	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			si *= -1;
		str++;
	}
	re = 0;
	while (*str >= '0' && *str <= '9')
	{
		re = (re * 10) + (*str - '0');
		str++;
	}
	return re * si;
}

int	main (void)
{
	printf("%d\n", ft_atoi("100"));
	return 0;
}
