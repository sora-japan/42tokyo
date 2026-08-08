/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 08:29:22 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 09:55:32 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (stc[i])
	{
		dest[i] = stc[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	dest1[100];
	char	*src1;
	char	*start;

	start =t_strcpy(dest1, src1);
	return (0);
}
