/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 20:13:02 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/05/18 23:04:42 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_printf_percent(int *check)
{
	if (*check == -1)
		return (-1);
	*check = write(1, "%", 1);
	if (*check == -1)
		return (-1);
	return (1);
}
