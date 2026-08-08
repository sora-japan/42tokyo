/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:24:56 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/08 18:35:59 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//char	*gyaku(char *str)
//{
//	int	i;
//	int len;
//	char tmp;
//
//	len = 0;
//	while (str[len])
//		len++;
//	i = 0;
//	while (i < ((len - 1) / 2))
//	{
//		tmp = str[i];
//		str[i] = str[len - i - 1];
//		str[len - i - 1] = tmp;
//		i++;
//	}
//	return str;
//}
//
//#include <stdio.h>
//
//int main()
//{
//	char nao[] = "love";
//	char *str;
//	str = gyaku(nao);
//	printf("%s\n", str);
//	return 0;
//}

int atoi(char *str)
{
	int	sign = 1;
	int	re = 0;
	int i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		re = (re * 10) + (str[i] - '0');
		i++;
	}
	return re * sign;
}

#include <stdio.h>

int	main()
{
	printf("%d\n", atoi("-12345"));
	return 0;
}
