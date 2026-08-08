/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:08:00 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/05/10 19:14:54 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*little == '\0')
		return (big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i] && big[i + j] == little[j] && i + j < len)
		{
			j++;
		}
		if (!little[j])
			return (&big[i]);
		i++;
	}
	return (NULL);
}
