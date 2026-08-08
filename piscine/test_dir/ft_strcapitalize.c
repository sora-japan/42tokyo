/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:28:52 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/24 23:42:56 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i - 1] >= '0' && str[i - 1] <= '9')
			flag = 1;
		else if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
			flag = 1;
		else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			flag = 1;
		else
			flag = 0;
		if (flag == 1 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if(flag == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int	main(void)
{
	char	str[] = "HI, HOW ARE YOU? 42WORDS FORTY-TWO; FIFTY+AND+ONE";
	printf("%s", ft_strcapitalize(str));
}
