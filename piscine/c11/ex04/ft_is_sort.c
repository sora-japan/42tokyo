/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 05:10:57 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/06 14:49:07 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

//int	comparison(int a, int b)
//{
//	if (a < b)
//		return (-1);
//	else if (a == b)
//		return (0);
//	else
//		return (1);
//}
//
//#include <stdio.h>
//
//int	main(void)
//{
//	int	ans;
//	int	tab[] = {1, 2, 2, 4, 5};
//	ans = ft_is_sort(tab, 5, &comparison);
//	printf("%d", ans);
//	return (0);
//}
