/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 06:40:14 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/26 20:21:09 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	ans;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	ans = 0;
	while (*str >= '0' && *str <= '9')
	{
		ans = (ans * 10) + (*str - '0');
		str++;
	}
	return (ans * sign);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	char	*str1;
//	int		ans1;
//
//	str1 = " ---+--+1234ab567";
//	ans1 = ft_atoi(str1);
//	printf("%d\n", ans1);
//	return (0);
//}
