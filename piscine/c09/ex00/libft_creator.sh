# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfujikaw <tfujikaw@student.42tokyo.jp      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/02 00:54:58 by tfujikaw          #+#    #+#              #
#    Updated: 2026/04/05 02:18:30 by tfujikaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/sh
cc -Wall -Wextra -Werror -c ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar rc libft.a *.o
ranlib libft.a
rm *.o
