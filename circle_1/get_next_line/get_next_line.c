/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujikaw <tfujikaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:05:42 by tfujikaw          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by tfujikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	grow(t_save *s, size_t need)
{
	char	*new;
	size_t	cap;
	size_t	i;

	if (need <= s->cap)
		return (1);
	cap = s->cap;
	if (cap == 0)
		cap = BUFFER_SIZE + 1;
	while (cap < need)
		cap *= 2;
	new = malloc(cap);
	if (!new)
		return (0);
	i = 0;
	while (i < s->len)
	{
		new[i] = s->data[i];
		i++;
	}
	free(s->data);
	s->data = new;
	s->cap = cap;
	return (1);
}

static int	append(t_save *s, char *buf, size_t n)
{
	size_t	i;

	if (!grow(s, s->len + n))
		return (0);
	i = 0;
	while (i < n)
	{
		s->data[s->len + i] = buf[i];
		i++;
	}
	s->len += n;
	return (1);
}

static int	fill_save(int fd, t_save *s)
{
	char	*buf;
	ssize_t	n;
	size_t	start;

	if (nl_pos(s, 0) >= 0)
		return (1);
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (0);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (free(buf), 0);
		start = s->len;
		if (!append(s, buf, (size_t)n))
			return (free(buf), 0);
		if (nl_pos(s, start) >= 0)
			break ;
	}
	free(buf);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_save	s;
	char			*line;
	size_t			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!fill_save(fd, &s) || s.len == 0)
	{
		reset_save(&s);
		return (NULL);
	}
	line = str_line(&s, &len);
	if (!line)
	{
		reset_save(&s);
		return (NULL);
	}
	consume(&s, len);
	return (line);
}
