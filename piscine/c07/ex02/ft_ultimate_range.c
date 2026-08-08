/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:39:24 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/31 11:45:58 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	if (min >= max)
		return (0);
	len = max - min;
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (len);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	int	size1;
//	int	*range1;
//	int	i;
//	int max;
//	int min;
//
//	max = 30;
//	min = -10;
//	size1 = ft_ultimate_range(&range1, min, max);
//	printf("%d\n", size1);
//	i = 0;
//	while (max > min)
//	{
//		printf("%d\n", range1[i]);
//		i++;
//		min++;
//	}
//	free(range1);
//}
