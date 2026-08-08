/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 03:10:12 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/29 20:54:31 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	j;

	while (argc > 1)
	{
		j = 0;
		while (argv[argc - 1][j])
			j++;
		write(1, argv[argc - 1], j);
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
