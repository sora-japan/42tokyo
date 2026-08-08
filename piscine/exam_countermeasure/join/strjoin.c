/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:32:03 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/02 18:32:08 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// segufo mojisuu?
// while ?

char *len_size_malloc(int size, char **strs, char *sep)
{
	int	len;
	int	count;
	int ans;
	char	*p;
	int	k;
	int len_count;

	len_count = 0;
	k = 0;
	while(size > k)
	{	
		len = 0;
		while (strs[k][len])
			len++;
		k++;
		len_count += len;
	}
	count = 0;
	while (sep[count])
		count++;
	ans = len_count + (count * (size - 1));
	p = (char *)malloc(sizeof(char) * (ans + 1));
	if (!p)
		return ((void *)0);
	return p;
}
// size hairetu kazu
// strs main str
// renkeu str
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join; //koko ni renketu
	int	i;
	int j;
	int k;
	int s;

	join = len_size_malloc(size, strs, sep);
	if (!join)
		return NULL;
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			join[k] = strs[i][j];
			k++;
			j++;
		}
		s = 0;
		if (i < size - 1)
		{
			while (sep[s])
			{
				join[k] = sep[s];
				k++;
				s++;
			}
		}
		i++;
	}
	join[k] = '\0';

	return join;
}

int	main(int argc, char **argv)
{
	char	*ans;
	char	*sep;

	sep = "www";
	ans = ft_strjoin(argc, argv, sep);
	if(!ans)
		return 0;
	printf("%s", ans);
	free(ans);
	return 0;
}
