/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:04:39 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/27 21:23:20 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

//int	main(int argc, char **argv)
int	main(void)
{
	int	i;

	i = 0;
	if(i < 4)
	{
		while(i < 4)
		{
			i++;
			printf("%d\n", i);
		}	
	}
}
