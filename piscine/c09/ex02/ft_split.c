/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 11:26:43 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/07 21:42:09 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	word_true_false(char c, char *charset)
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

int	word_len(char *str, char *charset)
{
	int		len;

	len = 0;
	while (str[len] && !word_true_false(str[len], charset))
		len++;
	return (len);
}

int	wsc(char *str, char *charset)
{
	int		i;
	int		count_w;

	i = 0;
	count_w = 0;
	while (str[i])
	{
		while (str[i] && word_true_false(str[i], charset))
			i++;
		if (str[i])
		{
			count_w++;
			while (str[i] && !word_true_false(str[i], charset))
				i++;
		}
	}
	return (count_w);
}

char	*ft_strdup(char *str, char *charset)
{
	char	*cpy;
	int		i;
	int		len;

	len = word_len(str, charset);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(char *str, char *charset)
{
	char	**word;
	int		i;
	int		j;

	word = (char **)malloc(sizeof(char *) * (wsc(str, charset) + 1));
	if (!word)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && word_true_false(str[i], charset))
			i++;
		if (str[i])
		{
			word[j] = ft_strdup(&str[i], charset);
			j++;
			while (str[i] && !word_true_false(str[i], charset))
				i++;
		}
	}
	word[j] = NULL;
	return (word);
}

#include <stdio.h>

void print_tab(char **tab)
{
    int i = 0;
    if (!tab)
    {
        printf("(null tab)\n");
        return;
    }
    while (tab[i] != NULL)
    {
        printf("tab[%d]: [%s]\n", i, tab[i]);
        i++;
    }
    printf("tab[%d]: NULL\n", i);
}

int main(void)
{
    char **result;

    printf("--- Test 1: Normal ---\n");
    result = ft_split("sssssassbsscsssss", "ss");
    print_tab(result);

    printf("\n--- Test 2: Multi separators ---\n");
    result = ft_split("   VEE VdyvTHjLJjDcebtGm07NKcPIWvKOTe  Di", " Di");
    print_tab(result);

    printf("\n--- Test 3: Only separators ---\n");
    result = ft_split("!!!!!", "!");
    print_tab(result);

    printf("\n--- Test 4: Empty string ---\n");
    result = ft_split("", "abc");
    print_tab(result);

    return (0);
}
