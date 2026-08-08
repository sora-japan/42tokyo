/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:22:08 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 15:38:42 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int count_words(char *str)
{
	int	count = 0;
	int	i = 0;
	while(str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if(str[i])
		{
			count++;
			while (!(str[i] == ' ' || str[i] == '\t'))
				i++;
		}
	}
	return count;
}

#include <stdio.h>

int main()
{
	int count;
	count = count_words("aiueo kakiku sasisu");
	printf("%d\n", count);
	return 0;
}
