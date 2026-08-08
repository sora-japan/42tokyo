/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:26:10 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/08 15:58:59 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    *ft_strrev(char *str)
{
	int i;
	char	tmp;
	int	len;
	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return str;
}

#include <stdio.h>

int	main(void)
{
	char moji[] = "Hello";
	char *str;
	str = ft_strrev(moji);
	printf("%s\n", str);
}
