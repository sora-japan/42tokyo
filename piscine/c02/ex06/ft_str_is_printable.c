/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:27:20 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/28 16:28:10 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (!(*str >= 32 && *str <= 126))
			return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;

	str1 = " !#%&'()*+,-./";
	str2 = "ABKHabchdjfSGW";
	str3 = "123456789";
	str4 = "";
	str5 = "\n\n\n\n\n283921";
	printf("記号:%d\n", ft_str_is_printable(str1));
	printf("英語:%d\n", ft_str_is_printable(str2));
	printf("数字:%d\n", ft_str_is_printable(str3));
	printf("空:%d\n", ft_str_is_printable(str4));
	printf("表示文字ではないもの:%d\n", ft_str_is_printable(str5));
}
