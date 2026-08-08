/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 03:04:22 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	nl_pos(t_save *s, size_t from)
{
	size_t	i;

	i = from;
	while (i < s->len)
	{
		if (s->data[i] == '\n')
			return ((ssize_t)i);
		i++;
	}
	return (-1);
}

void	reset_save(t_save *s)
{
	free(s->data);
	s->data = NULL;
	s->len = 0;
	s->cap = 0;
}

char	*str_line(t_save *s, size_t *len)
{
	char	*line;
	ssize_t	pos;
	size_t	i;

	pos = nl_pos(s, 0);
	if (pos < 0)
		*len = s->len;
	else
		*len = (size_t)pos + 1;
	line = malloc(*len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < *len)
	{
		line[i] = s->data[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	consume(t_save *s, size_t len)
{
	size_t	i;

	i = 0;
	while (len + i < s->len)
	{
		s->data[i] = s->data[len + i];
		i++;
	}
	s->len = i;
}
