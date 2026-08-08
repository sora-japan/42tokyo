/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:41:54 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/08 15:00:09 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	len;
	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	len = 0;
	while(argv[1][len])
		len++;
	while (argv[1][i])
	{
		write(1, &argv[1][i], 1);
		if (i < len - 1)
			write (1, "   ", 3);
		i++;
	}
	write (1, "\n", 1);
	return 0;
}
