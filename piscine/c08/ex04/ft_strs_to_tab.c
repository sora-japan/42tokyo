/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:59:04 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/08 02:19:00 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*copy;

	len = 0;
	while (str[len])
		len++;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			len;
	t_stock_str	*str_size;

	str_size = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (str_size == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		len = 0;
		while (av[i][len])
			len++;
		str_size[i].size = len;
		str_size[i].str = av[i];
		str_size[i].copy = ft_strdup(av[i]);
		i++;
	}
	str_size[i].str = 0;
	return (str_size);
}

//#include <stdio.h>
//
//void	printf_struct(t_stock_str str)
//{
//	printf("size : %d\nstr : %s\nstr_copy : %s\n", str.size, str.str, str.copy);
//}
//
//int	main(int argc, char **argv)
//{
//	int	i;
//
//	i = 0;
//	t_stock_str *struc;
//
//	struc = ft_strs_to_tab(argc, argv);
//	if(struc == NULL)
//		return (0);
//	while (i < argc)
//	{
//		printf_struct(struc[i]);
//		i++;
//	}
//	free(struc);
//	return (0);
//}
