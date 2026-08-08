/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:23:35 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/21 02:17:07 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	suuji;

	suuji = 48;
	while (suuji <= 57)
	{
		write(1, &suuji, 1);
		suuji++;
	}
}
//int	main(void)
//{
//	ft_print_numbers();
//	return (0);
//}
