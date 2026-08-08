/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 20:13:02 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/05/18 22:57:35 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_printf_c(char c, int *check)
{
	if (*check == -1)
		return (-1);
	*check = write(1, &c, 1);
	if (*check == -1)
		return (-1);
	return (1);
}
