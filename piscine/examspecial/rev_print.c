/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 20:58:46 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 21:04:15 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	len = 0;
	while (argv[1][len])
		len++;
	len--;
	while (argv[1][len])
	{
		write(1, &argv[1][len], 1);
		len--;
	}
	write(1, "\n", 1);
	return 0;
}
