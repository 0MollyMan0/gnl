/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:41:39 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/05 15:13:42 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract(char *s, int end)
{
	int	x;
	char	*sub;

	if (!s)
		return (NULL);
	sub = malloc(end + 2);
	if (!sub)
	{
		return (NULL);
	}
	x = 0;
	while (x <= end)
	{
		sub[x] = s[x];
		x++;
	}
	sub[x] = '\0';
	return (sub);
}
static int read_file(char **stash, char *buffer, int fd)
{
	int i;

	i = 1;
	while (ft_strchr_i(*stash, '\n') == -1 && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (-2);
		buffer[i] = '\0';
		*stash = ft_strjoin(*stash, buffer);
	}
	if ((i = ft_strchr_i(*stash, '\n')) >= 0)
		return (i);
	return (-1);
}
static char	*eof(char **stash)
{
	char *line;
	
	if (!*stash)
		return NULL;
	line = *stash;
	*stash = NULL;
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = read_file(&stash, buffer, fd);
	free(buffer);
	if (i >= 0)
	{
		line = extract(stash, i);
		stash = ft_substr(stash, i + 1);
		return (line);
	}
	if (i == -2)
		return (NULL);
	return (eof(&stash));
}
