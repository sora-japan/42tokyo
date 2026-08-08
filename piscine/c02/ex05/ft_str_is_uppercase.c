/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:02:40 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/24 03:58:52 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
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
	char	*str4;

	str1 = "ABC";
	str2 = "abc123";
	str3 = "ABCabc";
	str4 = "";
	printf("大文字のみ:%d\n", ft_str_is_uppercase(str1));
	printf("大文字と数字;%d\n", ft_str_is_uppercase(str2));
	printf("大文字と小文字:%d\n", ft_str_is_uppercase(str3));
	printf("空のみ:%d\n", ft_str_is_uppercase(str4));
}
*/
