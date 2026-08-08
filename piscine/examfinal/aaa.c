/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aaa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:29:55 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/08 17:24:38 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    count_alen(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			return i;
		i++;
	}
	return i;
}

int	strlen (*str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	return i;
}

int occ_a(char *str)
{
	int	i;
	int count;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'A')
			count++;
		i++;
	}
	return count;
}

#include <stdio.h>

int main()
{
	printf("%d\n", count_alen("Hello"));
	return 0;
}
