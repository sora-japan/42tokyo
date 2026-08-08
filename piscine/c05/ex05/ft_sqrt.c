/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 14:57:01 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/28 22:28:53 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	ans;

	ans = 1;
	while (ans <= nb / ans)
	{
		ans++;
		if ((ans * ans) == nb)
			return (ans);
	}
	return (0);
}
//#include <stdio.h>
//
//int	main(void)
//{
//	printf("%d\n", ft_sqrt(25));	
//	printf("%d\n", ft_sqrt(5));	
//}
