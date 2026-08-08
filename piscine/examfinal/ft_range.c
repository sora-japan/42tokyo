/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:39:55 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 15:58:21 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int	*range;
	int i = 0;
	int size;
	int step;
	if (start <= end) //要素数は絶対値＋１
		size = end - start + 1;
	else
		size = start - end + 1;
	range = (int *)malloc(sizeof(int) * (size));
	if(!range)
		return (NULL);
	if (start <= end)
		step = 1;
	else
		step = -1;

	while(i < size)
	{
		range[i] = start;
		start += step;
		i++;
	}
	return range;//rangeを返す
}
