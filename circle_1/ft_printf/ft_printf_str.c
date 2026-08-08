/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 20:19:30 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/05/18 20:37:31 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_printf_str(char *str, int *check)
{
	int	len;

	if (*check == -1)
		return (-1);
	if (!str)
	{
		*check = write(1, "(null)", 6);
		if (*check == -1)
			return (-1);
		return (6);
	}
	len = (int)ft_strlen(str);
	*check = write(1, str, len);
	if (*check == -1)
		return (-1);
	return (len);
}
