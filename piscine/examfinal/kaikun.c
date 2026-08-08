/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kaikun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 03:17:25 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 03:28:53 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char    *ft_strrev(char *str)
{
	int i;
	int len;
	char tmp;

	len = 0;
	while(str[len])
	len++;
	i = 0;
	while(i < len / 2)
	{
		tmp = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = tmp;
		i++;
	}
	return(str);

}

int main()
{
 	char c[] = "123456789";
	printf("%s\n", ft_strrev(c));
	return(0);
}
