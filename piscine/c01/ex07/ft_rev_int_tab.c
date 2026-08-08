/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 20:55:34 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/07 00:32:15 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

//#include <stdio.h>
//
//int	main(void)
//{ 
//	int	tab[] = {1, 2, 3, 4, 5, 6, 7};
//
//	ft_rev_int_tab(&tab[0], 7);
//	
//	int i;
//	i = 0;
//	while(i < 7)
//	{
//		printf("%d", tab[i]);
//		i++;
//	}
//}
