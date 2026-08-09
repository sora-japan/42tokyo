/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:05:50 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef LINE_DELIMITER
#  define LINE_DELIMITER '\n'
# endif

typedef struct s_save
{
	char	*data;
	size_t	off;
	size_t	len;
	size_t	cap;
}	t_save;

char	*get_next_line(int fd);
ssize_t	nl_pos(t_save *s, size_t from);
void	reset_save(t_save *s);
char	*str_line(t_save *s, size_t *len);
void	consume(t_save *s, size_t len);

#endif
