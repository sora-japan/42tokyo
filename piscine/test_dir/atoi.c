/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:27:43 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/26 21:54:34 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	ans;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	ans = 1;
	while (*str >= '0' && *str <= '9')
	{
		ans = (ans * 10) + (*str - '0');
		str++;
	}
	return ans * sign;
}

int main(void)
{
	printf("%d\n", ft_atoi("----++-7385dada629"));
	return (0);
}
