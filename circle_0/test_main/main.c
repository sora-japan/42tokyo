/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 02:31:15 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/04/26 18:54:07 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


void alpha_check(int c)
{
	int	real = isalpha(c);
	int	self = ft_isalpha(c);
	if ((real == 0 && self == 0) || (real != 0 && self != 0))
	{
		printf("\x1b[32m");
		printf("%s\n", "ok!");
	}
	else
	{
		printf("\x1b[31m");
		printf("%s\n", "error!");
	}
}

void digit_check(int c)
{
	int	real = isdigit(c);
	int	self = ft_isdigit(c);
	if ((real == 0 && self == 0) || (real != 0 && self != 0))
	{
		printf("\x1b[32m");
		printf("%s\n", "ok!");
	}
	else
	{
		printf("\x1b[31m");
		printf("%s\n", "error!");
	}
}

void alnum_check(int c)
{
	int	real = isalnum(c);
	int	self = ft_isalnum(c);
	if ((real == 0 && self == 0) || (real != 0 && self != 0))
	{
		printf("\x1b[32m");
		printf("%s\n", "ok!");
	}
	else
	{
		printf("\x1b[31m");
		printf("%s\n", "error!");
	}
}

void ascii_check(int c)
{
	int	real = isascii(c);
	int	self = ft_isascii(c);
	if ((real == 0 && self == 0) || (real != 0 && self != 0))
	{
		printf("\x1b[32m");
		printf("%s\n", "ok!");
	}
	else
	{
		printf("\x1b[31m");
		printf("%s\n", "error!");
	}
}

void print_check(int c)
{
	int	real = isprint(c);
	int	self = ft_isprint(c);
	if ((real == 0 && self == 0) || (real != 0 && self != 0))
	{
		printf("\x1b[32m");
		printf("%s\n", "ok!");
	}
	else
	{
		printf("\x1b[31m");
		printf("%s\n", "error!");
	}
}

void	memset_check(void)
{
    char    b[5];
    char    a[5];
    memset(b, '0', 5);
    b[4] = '\0';
    ft_memset(a, '0', 5);
    a[4] = '\0';

    printf("memset == %s\n", b);
    printf("ft_memset == %s\n", a);
}

void	bzero_check(void)
{

    char    a[6] = "aiueo";
    char    b[6] = "aiueo";

    bzero(a, 5);
    ft_bzero(b, 5);
    printf("bzero == ");
    printf("%d\n", a[0]);
    printf("ft_bzero == ");
    printf("%d\n", b[0]);
    printf("bzero == ");
    printf("%d\n", a[5]);
    printf("ft_bzero == ");
    printf("%d\n", b[5]);

}

void	memcpy_check(void)
{
	char	destt[15];
	char	srcc[6] = "aiueo";
	char	dest[15];
	char	src[6] = "aiueo";

	memcpy(destt, srcc, 6);
	ft_memcpy(dest, src, 6); 
	printf("%s", "memcpy = ");
	printf("%s\n", destt);
	printf("%s", "ft_memcpy = ");
	printf("%s\n", dest);
}

void	memmove_check(void)
{
    char    destt[15];
    char    srcc[6] = "aiueo";
    char    dest[15];
    char    src[6] = "aiueo";
    char    *a;
	char	*b;

	b = memmove(destt, srcc, 6); 
    a = ft_memmove(dest, src, 6);
	printf("%s", "memmove = ");
    printf("%s\n", b);
	printf("%s", "ft_memmove = ");
    printf("%s\n", a);
}

void	strlcpy_check(void)
{
    char    dest[2];
    const char  *src = "Hello 42 Tokyo";

    char    destt[2];
    const char  *srcc = "Hello 42 Tokyo";

    size_t a = strlcpy(destt, srcc, sizeof(destt));
    size_t b = ft_strlcpy(dest, src, sizeof(dest));

	printf("%s", "strlcpy = ");
    printf("%s\n", destt);
	printf("%s", "ft_strlcpy = ");
    printf("%s\n", dest);
	printf("%s", "strlcpy = ");
    printf("%zu\n", a);
	printf("%s", "ft_strlcpy = ");
    printf("%zu\n", b);
}

int	main(void)
{
	printf("%s\n", "---ft_isalpha---");
 	alpha_check('a');
 	alpha_check('z');
 	alpha_check('A');
 	alpha_check('Z');
 	alpha_check('0');
 	alpha_check('9');
 	alpha_check(' ');
 	alpha_check('!');
	printf("\x1b[0m");
	
	printf("%s\n", "---ft_isdigit---");
 	digit_check(0);
 	digit_check(9);
 	digit_check('0');
 	digit_check('9');
 	digit_check(100);
 	digit_check(300);
 	digit_check('!');
	printf("\x1b[0m");

	printf("%s\n", "---ft_isalnum---");
	alnum_check('a');
	alnum_check('z');
	alnum_check('A');
	alnum_check('Z');
	alnum_check(0);
	alnum_check(9);
	alnum_check('0');
	alnum_check('9');
	alnum_check('!');
	printf("\x1b[0m");

	printf("%s\n", "---ft_isascii---");
	ascii_check('a');
	ascii_check('z');
	ascii_check('0');
	ascii_check('9');
	ascii_check('\n');
	ascii_check('\t');
	ascii_check(128);
	ascii_check(0);
	printf("\x1b[0m");

	printf("%s\n", "---ft_isprint---");
	print_check(' ');
	print_check('~');
	print_check('a');
	print_check('z');
	print_check('A');
	print_check('Z');
	print_check(31);
	print_check(127);
	printf("\x1b[0m");

	printf("%s\n", "---ft_strlen---");
	printf("\x1b[33m");
	printf("strlen == %zu\n", strlen("aiueo"));
	printf("ft_strlen == %zu\n", ft_strlen("aiueo"));
	printf("strlen == %d\n", (int)strlen("aiueo"));
	printf("ft_strlen == %d\n", (int)ft_strlen("aiueo"));
	printf("\x1b[0m");

	printf("%s\n", "---ft_memset---");
	printf("\x1b[33m");
	memset_check();
	printf("\x1b[0m");

	printf("%s\n", "---ft_atoi---");
	printf("\x1b[33m");
    printf("atoi == ");
    printf("%d\n", atoi("   -1234ab12"));
    printf("ft_atoi == ");
    printf("%d\n", ft_atoi("   -1234ab12"));
	printf("\x1b[0m");

	printf("%s\n", "---ft_bzero---");
	printf("\x1b[33m");
	bzero_check();
	printf("\x1b[0m");

	printf("%s\n", "---ft_memcpy---");
	printf("\x1b[33m");
	memcpy_check();
	printf("\x1b[0m");

	printf("%s\n", "---ft_memmove---");
	printf("\x1b[33m");
	memmove_check();
	printf("\x1b[0m");

	printf("%s\n", "---ft_strlcpy---");
	printf("\x1b[33m");
	strlcpy_check();
	printf("\x1b[0m");

	return (0);
}
