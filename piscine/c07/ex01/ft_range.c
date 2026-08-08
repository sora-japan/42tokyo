/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:02:32 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/01 19:41:17 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*numbers;
	int	i;

	if (min >= max)
		return (NULL);
	numbers = (int *)malloc(sizeof(int) * (max - min));
	if (numbers == NULL)
		return (0);
	i = 0;
	while (max > min)
	{
		numbers[i] = min;
		min++;
		i++;
	}
	return (numbers);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	int	*ans;
//	int	i;
//
//	i = 0;
//	ans = ft_range(-10, 30);
//	while (i < 40)
//		printf("%d\n", ans[i++]);
//	free(ans);
//	return (0);
//}
