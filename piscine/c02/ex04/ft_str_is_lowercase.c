/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:50:31 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/23 19:38:33 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
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

	str1 = "abcde";
	str2 = "abCde";//Cが大文字
	str3 = "abc123";//数字
	str4 = "";
	printf("英語小文字のみ%d\n", ft_str_is_lowercase(str1));
	printf("英語、途中に大文字%d\n", ft_str_is_lowercase(str2));
	printf("英語と数字%d\n", ft_str_is_lowercase(str3));
	printf("空%d\n", ft_str_is_lowercase(str4));
	return (0);
}
*/
