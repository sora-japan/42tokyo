/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:37:49 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/08 01:47:03 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_baselen(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

int	check_base(char *base)
{
	int		i;
	char	used[256];

	if (ft_baselen(base) <= 1)
		return (0);
	i = 0;
	while (i < 256)
	{
		used[i] = 0;
		i++;
	}
	i = 0;
	while (base[i])
	{
		if ((base[i] <= ' ') || (base[i] > '~'))
			return (0);
		if ((base[i] == '-') || (base[i] == '+'))
			return (0);
		if (used[(unsigned char) base[i]])
			return (0);
		used[(unsigned char) base[i]] = 1;
		i++;
	}
	return (1);
}

int	get_base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		n;
	int		res;
	int		i;
	int		sign;

	n = ft_baselen(base);
	if (!check_base(base))
		return (0);
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && get_base_index(str[i], base) != -1)
	{
		res = (res * n) + get_base_index(str[i], base);
		i++;
	}
	return (res * sign);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	char	*base;
//	char	*str;
//
//	base = "poneyvif";
//	str = "on";
//	printf("%d\n", ft_atoi_base(str, base));
//	return (0);
//}
