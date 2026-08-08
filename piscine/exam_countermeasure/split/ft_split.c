/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 08:20:47 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/05 13:38:39 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	word_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *str, char *charset)
{
	int		i;
	int		len;
	char	*ans;

	len = 0;
	while (str[len] && !word_check(str[len], charset))
		len++;
	ans = malloc(len + 1);
	i = 0;
	while (str[i] && !word_check(str[i], charset))
	{
		ans[i] = str[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		word_count;
	int		len;
	char	**ans;

	len = 0;
	while (str[len])
		len++;
	ans = malloc(sizeof(char *) * (len + 1));
	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && word_check(str[i], charset))
			i++;
		if (str[i])
		{
			ans[word_count] = ft_strcpy(&str[i], charset);
			while (str[i] && !word_check(str[i], charset))
				i++;
			word_count++;
		}
	}
	ans[word_count] = NULL;
	return (ans);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	char    *str;
//	char    *charset;
//	char    **ans;
//	int		i;
//
//	str = "Hello. world. 42.";
//	charset = ". ";
//	ans = ft_split(str, charset);
//	i = 0;
//	while(ans[i])
//	{
//		printf("%s\n", ans[i]);
//		i++;
//	}
//	return (0);
//}
