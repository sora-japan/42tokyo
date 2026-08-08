/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:28:15 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/29 14:25:25 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s11;
	char	*s22;
	char	*s33;
	char	*s44;

	s11 = "apple";
	s22 = "apple";
	s33 = "banana";
	s44 = "appue";
	printf("s1 s2 比較結果:%d\n", ft_strcmp(s11, s22));
	printf("s1 s3 比較結果:%d\n", ft_strcmp(s11, s33));
	printf("s1 s4 比較結果:%d\n", ft_strcmp(s11, s44));
	printf("s1 s2 比較結果（本物）: %d\n", ft_strcmp(s11, s22));
	printf("s1 s3 比較結果（本物）: %d\n", ft_strcmp(s11, s33));
	printf("s1 s4 比較結果（本物）: %d\n", ft_strcmp(s11, s44));
	return (0);
}
*/
