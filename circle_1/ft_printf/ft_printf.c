/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:53:08 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/06/14 15:47:14 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_printf_help(const char *format, int i, va_list *ap, int *check)
{
	int	count;

	count = 0;
	if (*check == -1)
		return (-1);
	if (format[i] == 'c')
		count += ft_printf_c((char)va_arg(*ap, int), check);
	else if (format[i] == 's')
		count += ft_printf_str(va_arg(*ap, char *), check);
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_printf_di(va_arg(*ap, int), check);
	else if (format[i] == 'u')
		count += ft_printf_u(va_arg(*ap, unsigned int), check);
	else if (format[i] == 'x')
		count += ft_printf_x(va_arg(*ap, unsigned int), check);
	else if (format[i] == 'X')
		count += ft_printf_u_x(va_arg(*ap, unsigned int), check);
	else if (format[i] == 'p')
		count += ft_printf_p(va_arg(*ap, void *), check);
	else if (format[i] == '%')
		count += ft_printf_percent(check);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;
	int		check;

	i = 0;
	check = 0;
	va_start(ap, format);
	count = 0;
	while (format[i])
	{
		if (check == -1)
			break ;
		if (format[i] == '%' && format[i + 1])
			count += ft_printf_help(format, ++i, &ap, &check);
		else
			count += ft_printf_c(format[i], &check);
		i++;
	}
	if (check == -1)
		return (-1);
	va_end(ap);
	return (count);
}

/*
int	main(void)
{
	ft_printf("Hello, %s%d", "world", 42);
}

#include <stdio.h>

int	main(void)
{
	int				self;
	int				real;
	unsigned int	hex_num;
	char			*p;
	char			*p1;

	hex_num = 255;
	p = NULL;
	p1 = "Hello";
	self = 0;
	real = 0;
	ft_printf("\x1b[32m\n");
	ft_printf("---自作---\n\n");
	self += ft_printf("aiueo\n");
	self += ft_printf("c == %c\n", 'A');
	self += ft_printf("s == %s\n", "KKK");
	self += ft_printf("d == %d\n", -123);
	self += ft_printf("i == %i\n", -123);
	self += ft_printf("u == %u\n", -123);
	self += ft_printf("u == %u\n", 123);
	self += ft_printf("x == %x\n", hex_num);
	self += ft_printf("X == %X\n", hex_num);
	self += ft_printf("p == %p\n", p);
	self += ft_printf("p == %p\n", p1);
	self += ft_printf("%% == %%\n");
	printf("戻り値 == %d\n", self);
	printf("\x1b[31m\n");
	ft_printf("---本物---\n\n");
	real += printf("aiueo\n");
	real += printf("c == %c\n", 'A');
	real += printf("s == %s\n", "KKK");
	real += printf("d == %d\n", -123);
	real += printf("i == %i\n", -123);
	real += printf("u == %u\n", -123);
	real += printf("u == %u\n", 123);
	real += printf("x == %x\n", hex_num);
	real += printf("X == %X\n", hex_num);
	real += printf("p == %p\n", p);
	real += printf("p == %p\n", p1);
	real += printf("%% == %%\n");
	printf("戻り値 == %d\n", real);
	printf("\x1b[0m\n");
	ft_printf("%s\n %s\n, %s\n", NULL, NULL, NULL);
	printf("%s\n", (char *)NULL);
	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);
	ft_printf("%d\n", -2147483648);
	ft_printf("%d%s%%%x\n", 42, "hello", 255);
	ft_printf(NULL);
	return (0);
}
*/
