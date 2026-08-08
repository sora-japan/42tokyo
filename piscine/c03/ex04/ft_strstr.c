/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:35:33 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/01 12:58:03 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		t = i;
		while ((str[t] == to_find[j]) && to_find[j] != '\0')
		{
			j++;
			t++;
		}
		if (to_find[j] == '\0')
			return (str + i);
		i++;
	}
	return ((void *)0);
}
//#include <string.h>
//#include <stdio.h>
//
//int	main(void)
//{
//	char	str1[] = "Hello WoWorldld";
//	char	*ans;
//
//	ans = ft_strstr(str1, "World");
//	if (ans != NULL)
//		printf("発見！ %s\n", ans);
//	else
//		printf("未発見\n");
//	printf("以下本物\n");
//	char str2[] = "Hello WoWorldld";
//    char *p;
//
//    p = strstr(str2, "World");
//
//    if (p) {
//        printf("発見！ %s\n", p);
//    } else {
//        printf("未発見\n");
//    }
//	return (0);
//}
