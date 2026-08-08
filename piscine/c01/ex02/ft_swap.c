/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:33:51 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/07 00:29:55 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//#include <stdio.h>
//int	main(void)
//{
//	int		a2;
//	int		b2;
//
//	a2 = 5;
//	b2 = 9;
//	printf("%d\n", a2);
//	printf("%d\n", b2);
//	ft_swap(&a2, &b2);
//	printf("変更後%d\n", a2);
//	printf("変更後%d\n", b2);
//}
