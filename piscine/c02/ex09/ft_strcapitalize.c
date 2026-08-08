/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 02:17:56 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/03/24 03:57:20 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i - 1] >= '0' && str[i - 1] <= '9')
			flag = 1;
		else if ((str[i - 1] >= 'a' && str[i - 1] <= 'z'))
			flag = 1;
		else if ((str[i - 1] >= 'A' && str[i - 1] <= 'Z'))
			flag = 1;
		else
			flag = 0;
		if (flag == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		if (flag == 1 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[200] = "hi, how are you? 42words forty-two; fifty+and+one";
	printf("%s", ft_strcapitalize(&str[0]));
	return (0);
}
*/
