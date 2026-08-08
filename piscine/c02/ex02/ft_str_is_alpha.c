/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:03:28 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/23 19:37:30 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if ((!(*str >= 'A' && *str <= 'Z') && !(*str >= 'a' && *str <= 'z')))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "aiueo123kaki";
	str2 = "aiueo";
	str3 = "";
	printf("ローマ字以外を含む:%d\n", ft_str_is_alpha(str1));	
	printf("英字のみ:%d\n", ft_str_is_alpha(str2));
	printf("空:%d\n", ft_str_is_alpha(str3));
}
*/
