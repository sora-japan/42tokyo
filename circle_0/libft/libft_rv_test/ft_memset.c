/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 17:12:35 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/05/10 17:24:13 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *b1;
	size_t	i;

	i = 0;
	b1 = (unsigned char *)b;
	while (len--)
	{
		b1[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

#include <string.h>
#include <stdio.h>

int main() {
    int arr[10];
    // arrの先頭からsizeof(arr)バイト分を0で埋める
    // memset(arr, 0, sizeof(arr)); 
    ft_memset(arr, 0, sizeof(arr)); 
	int i = 0;
	while (i < 10)
	{
		printf("%d\n", arr[0]);
		i++;
	}
    return 0;
}

