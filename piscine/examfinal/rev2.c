/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:21:44 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/08 16:28:48 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
	int	i;
	int	len;
	char tmp;

	len = 0;
	while (str[len])
		len++;

	i = 0;
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

int main()
{
	char	*str;
	char	b[] = "Hello";
	str = ft_strrev(b);
	printf("%s\n", str);
}
