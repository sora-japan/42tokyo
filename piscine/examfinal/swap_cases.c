/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 03:10:55 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/09 04:02:02 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *swap_cases(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}	
		i++;
	}
	return str;
}

int main(void)
{
	while (str[i])
	{
		
	}
	return 0;
}
