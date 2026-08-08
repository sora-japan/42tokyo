/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:57:48 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 22:00:35 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char **ft_sort_params(int argc, char **argv)
{
	int	i;
	int	j;
	char *tmp;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) >= 1)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return argv;
}

void printf_sort(int argc, char **str)
{
	int	i;
	int	len;

	i = 1;
	while (i < argc)
	{
		len = 0;
		while(str[i][len])
			len++;
		write(1, str[i], len);
		write(1, "\n", 1);
		i++;
	}
}
	
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);

	ft_sort_params(argc, argv);
	printf_sort(argc, argv);
	return 0;
}
