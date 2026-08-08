/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 20:42:33 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/06 14:34:36 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*dest;
	int	i;

	dest = (int *)malloc(sizeof(int) * length);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dest[i] = f(tab[i]);
		i++;
	}
	return (dest);
}

//int plus(int nb)
//{
//	return nb + 1;
//}
//
//#include <stdio.h>
//
//int	main(void)
//{
//	int *p;
//	int	i;
//	int tab[5] = {1, 2, 3, 4, 5};
//
//	i = 0;
//	p = ft_map(tab, 5, &plus);
//	while (i < 5)
//	{
//		printf("%d\n", p[i]);
//		i++;
//	}
//	free(p);
//	return (0);
//}
