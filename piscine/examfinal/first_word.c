/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:12:03 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/08 23:36:15 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	if (argc != 2)
	{
		write (1, "\n", 1);
		return 0;
	}

	while (argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13))//タブなども飛ばす
		i++;
	while (argv[1][i] && !(argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)))
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
