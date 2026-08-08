/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 23:17:25 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/06 19:43:07 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len_malloc(int size, char **strs, char *sep)
{
	int		len;
	int		count;
	int		i;
	int		j;
	int		ans;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	count = 0;
	while (sep[count])
		count++;
	ans = len + (count * (size - 1));
	return (ans);
}

char	*malloc_join(int size, char **strs, char *sep)
{
	char	*join;
	int		ans;

	ans = ft_len_malloc(size, strs, sep);
	join = (char *)malloc(sizeof(char) * (ans + 1));
	if (!join)
		return (NULL);
	return (join);
}

char	*ft_strcpy_one(char	*join, char *str, int *i)
{
	int	j;

	j = 0;
	while (str[j])
	{
		join[*i] = str[j];
		(*i)++;
		j++;
	}
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		i;
	int		s;

	join = malloc_join(size, strs, sep);
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	i = 0;
	s = 0;
	while (size > s)
	{
		join = ft_strcpy_one(join, strs[s], &i);
		if (size - 1 > s)
			join = ft_strcpy_one(join, sep, &i);
		s++;
	}
	join[i] = '\0';
	return (join);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*s;
	char	*join_str;

	s = "world";
	join_str = ft_strjoin(argc, argv, s);
	printf("%s\n", join_str);
	free(join_str);
	return (0);
}
