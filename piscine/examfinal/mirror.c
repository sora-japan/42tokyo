/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 23:17:55 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 03:33:32 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	char c;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	while (argv[1][i])
	{
		c = argv[1][i];
		if (c >= 'a' && c <= 'z')
		{
			c = 'a' + 'z' - c;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c = 'A' + 'Z' - c;
		}
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
