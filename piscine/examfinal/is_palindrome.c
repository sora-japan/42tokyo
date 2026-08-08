/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_palindrome.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 06:02:16 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 08:37:46 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int	len;
	if (argc != 2)
	{
		write (1, "\n", 1);
		return 0;
	}
	len = 0;
	while (argv[1][len])
		len++;
	if (argv[1][0] == '\0')
	{
		write(1, "\n", 1);
		return 0;
	}
	i = 0;
	while (i < len / 2)
	{
		if(argv[1][i] != argv[1][len - 1 - i])
		{
			write(1, "\n", 1);
			return 0;
		}
		i++;
	}
	i = 0;
	while (argv[1][i])
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
