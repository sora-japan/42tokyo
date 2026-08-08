/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:41:56 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 22:45:59 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_cpy(char *dest, char *str, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n > i && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	while (n > i)
	{
		dest[i] = '\0';
		i++;
	}
	return dest;
}
