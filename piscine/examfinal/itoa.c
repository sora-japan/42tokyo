/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:58:33 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 17:04:02 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	i_len(long	n)
{
	int	len = 0;
	if(n == 0)
		return (1);
	if(n < 0)
	{
		len++; //マイナス符号の分を獲得
		n = -n;
	}
	while(n > 0) //０より大きい間回り続ける
	{
		n = n / 10; //何回割れるかで文字数を計算
		len++;
	}
	return len;
}

char    *ft_itoa(int nbr)
{
	long n;
	char *str;
	int	len;
	n =nbr;
	len = i_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0'; //最後にヌルを置く

	if(n == 0)//n == 0の時
	{
		str[0] = '0'; //0の場合は０を入れて終わり
		return str;
	}
	if(n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while(n > 0)
	{
		len--;
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return str;
}
