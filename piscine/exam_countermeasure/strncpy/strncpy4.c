/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 09:52:26 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/03 09:56:44 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ncpy(char *dest, char *str, unsigned int n)
{
	int	i;

	i = 0;
	while (n > i && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return dest;
}
