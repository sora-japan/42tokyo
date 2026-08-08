/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testrev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 03:34:18 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 04:00:02 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
	int	i = 0;
	int len = 0;
	char tmp;
	while (str[len])
		len++;
	while (i < (len / 2)) //len / 2 じゃないとバグるので注意
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];//てｍｐする際は、−１
		str[len - 1 - i] = tmp;
		i++;
	}
	return str;
}

#include <stdio.h>

int main()
{
	char c[] = "12345678";
	printf("%s\n", ft_strrev(c));
	return 0;
}
