/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_odd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 02:14:13 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 02:18:46 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc != 2)
	{
		write (1, "\n", 1);
		return 0;
	}
	while (argv[1][i])
	{
		if(i % 2 != 0)
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
