# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/07 20:06:04 by tfujikaw          #+#    #+#              #
#    Updated: 2026/05/20 17:12:01 by tfujikaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAG	= -Wall -Wextra -Werror
LIB_CMD	= ar rcs
RM		= rm -f

LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a

HEADER	= ft_printf.h

SRCS	=  ft_printf_u_x.c \
		   ft_printf_c.c \
		   ft_printf_di.c \
		   ft_printf_p.c \
		   ft_printf_percent.c \
		   ft_printf_str.c \
		   ft_printf_u.c \
		   ft_printf_x.c \
		   ft_printf.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(LIB_CMD) $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAG) -I $(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
