/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:32:28 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/07 00:31:09 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

//#include <stdio.h>
//int	main(void)
//{
//	int	a;
//	int	b;
//
//	a = 9;
//	b = 5;
//	ft_ultimate_div_mod(&a, &b);
//	printf("割り算の答え:%d\n", a);
//	printf("余り:%d\n", b);
//}
