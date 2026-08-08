/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:12:06 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 22:54:52 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				len;

	len = 0;
	i = 0;
	while (dest[len] != '\0')
		len++;
	while (src[i] && i < nb)
	{
		dest[i + len] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s11[20] = "apple ";
	char	*s22;
	int		n;

	s22 = "store";
	n = 3;
	printf("%s\n", ft_strncat(s11, s22, n));
	printf("以下本物");
	char	s12[20] = "apple ";
	printf("%s\n", strncat(s12, s22, n));
	return (0);
}
*/
