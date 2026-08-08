/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 04:45:25 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/08 03:27:31 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
//#include <stdio.h>
//#include <string.h>
//
//int	main(void)
//{
//	char	*s11;
//	char	*s22;
//	char	*s33;
//	char	*s44;
//	char	*s55;
//
//	s11 = "apple";
//	s22 = "appuu";
//	s33 = "banana";
//	s44 = "a";
//	s55 = "b";
//
//	printf("%d\n", ft_strncmp(s11, s22, 3));
//	printf("%d\n", strncmp(s11, s22, 3));
//	
//	printf("%d\n", ft_strncmp(s11, s33, 3));
//	printf("%d\n", strncmp(s11, s33, 3));
//
//	printf("%d\n", ft_strncmp(s11, s44, 3));
//	printf("%d\n", strncmp(s11, s44, 3));
//	
//	printf("%d\n", ft_strncmp(s11, s55, 3));
//	printf("%d\n", strncmp(s11, s55, 3));
//	return 0;	
//}
