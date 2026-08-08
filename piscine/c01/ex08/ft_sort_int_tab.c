/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 11:18:59 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/07 00:32:57 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

// #include <stdio.h>
//int	main(void)
//{
//	int tab[5];
//
//	tab[0] = 5;
//	tab[1] = 3;
//	tab[2] = 4;
//	tab[3] = 1;
//	tab[4] = 2;
//	ft_sort_int_tab(&tab[0], 5);
//
//	int	i;
//
//	i = 0;
//	while (i < 5)
//	{
//		printf("%d", tab[i]);
//		i++;
//	}
//}
