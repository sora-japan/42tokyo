/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:00:54 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 11:25:35 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	int len;
	
	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (size - 1> i && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (0); 
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[0];
	//printf("real\n");
	//printf("%d\n", strlcpy(dest, "Hello, World", sizeof(dest)));
	printf("my\n");
	printf("%d\n", ft_strlcpy(dest, "Hello, World", sizeof(dest)));
	printf("%s", dest);
	return (0);
}
