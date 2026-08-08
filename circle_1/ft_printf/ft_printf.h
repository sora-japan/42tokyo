/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 17:50:18 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/05/20 17:11:38 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_printf_c(char c, int *check);
int	ft_printf_str(char *str, int *check);
int	ft_printf_di(int n, int *check);
int	ft_printf_u(unsigned int n, int *check);
int	ft_printf_x(unsigned int n, int *check);
int	ft_printf_u_x(unsigned int n, int *check);
int	ft_printf_p(void *p, int *check);
int	ft_printf_percent(int *check);

#endif
