/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 17:25:23 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/05/10 17:45:02 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d_len;
	size_t s_len;	
	size_t i;
	size_t total

	i = 0;
	d_len = 0;
	s_len = ft_strlen(src);
	while (dst[d_len] && d_len < size)
		d_len++;
	if (d_len == size)
		return (size + s_len);
	total = s_len + d_len;
	while (src[i] && i < (size - d_len - 1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	det[d_len + i] = '\0';
	return (total);
}
