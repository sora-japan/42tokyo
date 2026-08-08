/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 03:34:49 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/06 14:48:41 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

//int	zozotown(char *str)
//{
//	int	i;
//
//	i = 0;
//	while (str[i])
//	{
//		if (str[i] != 'z')
//			return (1);
//		i++;
//	}
//	return (0);
//}
//#include <stdio.h>
//
//int	main(void)
//{
//	int	count;
//	char	*tab[] = {"zbz", "zzz", NULL};
//	count = ft_count_if(tab, 2, &zozotown);
//	printf("%d\n", count);
//	return (0);
//}
