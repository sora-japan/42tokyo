/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 02:21:54 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 02:33:51 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	while (argv[1][i])
	{
		char c = argv[1][i];
		if (c != 'z' && (c >= 'a' && c <= 'y'))
		{
			c += 1;
		}
		else if (c == 'z')
		{
			c = 'a';
		}
		else if (c != 'Z' && (c >= 'A' && c <= 'Y'))
			c += 1;
		else if (c == 'Z')
			c = 'A';
		write(1, &c, 1);
		i++;
	}
	write (1, "\n", 1);
	return 0;
}
