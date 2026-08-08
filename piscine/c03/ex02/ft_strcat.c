/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:44:48 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/26 03:14:34 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[i] != '\0')
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest1[20] = "hello ";
	char	*src1;

	src1 = "world";
	printf("%s\n", ft_strcat(&dest1[0], src1));
	printf("以下本物\n");
	char	dest2[20] = "hello ";
	
	printf("%s\n", strcat(&dest2[0], src1));
	return (0);
}
*/
