/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:10:14 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/21 02:10:45 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	alfa;

	alfa = 97;
	while (alfa <= 122)
	{
		write (1, &alfa, 1);
		alfa++;
	}
}
//int main (void)
//{
//	ft_print_alphabet();
//	return (0);
//}
