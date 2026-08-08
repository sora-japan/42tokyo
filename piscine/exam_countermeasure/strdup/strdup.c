/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:37:01 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 19:21:51 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src)
{
	char	 *res;
	int	i;
	int len;

	len = 0;
	while (src[len])
		len++;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return NULL;
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int main(void)
{
	char	*src;
	char	*dest;
	src = "hello";
	dest = ft_strdup(src);
	printf("%s", dest);
	free(dest);
	return 0;
}
