/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 08:42:18 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/07 00:33:55 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// #include <stdio.h>
//int	main(void)
//{
//	int	a;
//	int	b;
//	int	div;
//	int	mod;
//
//	a = 9;
//	b = 5;
//	div = 0;
//	mod = 0;
//	ft_div_mod(a, b, &div, &mod);
//	printf("a ÷ b =  %d\n", div);
//	printf("a ÷ b　の余りは %d\n", mod);
//	return (0);
//}
