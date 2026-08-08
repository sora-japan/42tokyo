/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:08:15 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/24 03:59:23 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "12345";
	str2 = "12345abc";
	str3 = "";
	printf("数字のみ:%d\n", ft_str_is_numeric(str1));
	printf("数字以外も含む:%d\n", ft_str_is_numeric(str2));
	printf("空のみ:%d\n", ft_str_is_numeric(str3));
}
*/
