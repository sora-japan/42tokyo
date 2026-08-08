/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:12:21 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 13:15:39 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pr_atoi(const char *nb)
{
	int si;
	int	re;

	while (*nb == ' ' || (*nb >= 9 && *nb <= 13))
		nb++;
	si = 1;
	if (*nb == '-' || *nb == '+')
	{
		if (*nb == '-')
			si *= -1;
		nb++;
	}
	re = 0;
	while (*nb >= '0' && *nb <= '9')
	{
		re = (re  * 10) + (*nb - '0');
		nb++;
	}
	return re * si;
}

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%d\n", pr_atoi("2147483647"));
	printf("%d\n", atoi("2147483647"));
	printf("-----\n");	
	printf("%d\n", pr_atoi("2147483648"));
	printf("%d\n", atoi("2147483648"));
	printf("-----\n");	
	printf("%d\n", pr_atoi("  --1234ab1"));
	printf("%d\n", atoi("  --1234ab1"));
	
	return 0;
}
