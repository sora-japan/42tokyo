/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_intrval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:51:26 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 02:09:02 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	while (argv[1][i])
	{
		if (i > 0 && ((i % 3) == 0) && ((i % 5)) == 0)
			argv[1][i] = '5';
		else if ((i > 0 && i % 3) == 0)
			argv[1][i] = '5';
		else if	(i > 0 &&(i % 5) == 0)
			argv[1][i] = '3';
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
