/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:07:01 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 12:10:09 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*cpy;
	int		i;

	len = 0;
	while (src[len] != '\0')
		len++;
	cpy = (char *)malloc(sizeof(char) * len + 1);
	if (!cpy)
		return ((void *)0);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
//
//#include <stdio.h>
//
//int	main(void)
//{
//	char	*src1;
//	char	*str;
//
//	src1 = "Hello World";
//	str = ft_strdup(src1);
//	printf("%s\n", str);
//	free(str);
//	return (0);
//}
