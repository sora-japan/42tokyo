/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:48:53 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 19:20:11 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	char	dest[12];
//	char	*src1;
//	int		n1;
//
//	n1 = 5;
//	src1 = "HelloWorld";
//
//	ft_strncpy(dest, src1, n1);
//	printf("%s", dest);
//	return (0);
//}
//
