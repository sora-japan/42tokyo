/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 22:25:47 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/06 14:48:28 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

//int no_five(char *str)
//{
//	int	i;
//
//	i = 0;
//	while (str[i])
//	{
//		if (str[i] == 'a')
//			return (1);
//		i++;
//	}
//	return (0);
//}
//#include <stdio.h>
//
//int	main(void)
//{
//	int result;
//	char  *tab[] = {"xbde", "bcdef", "cdefg", NULL};
//
//	result = ft_any(tab, &no_five);
//	printf("%d\n", result);
//	return (0);
//}
