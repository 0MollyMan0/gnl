/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:41:39 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/05 10:57:08 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = read(fd, buffer, BUFFER_SIZE);
	if (i > 0)
	{
		buffer[i] = '\0';
		stash = ft_strjoin(stash, buffer);
		free(buffer);
		if ((i = ft_strchr_i(stash, '\n')) >= 0)
		{
			line = extract(stash, i);
			stash = substr(stash, i + 1);
			return (line);
		}
	}
	else if (i == 0 && stash)
		return(eof(buffer, stash));
	return (NULL);
}

static char	*eof(char *buffer, char *stash)
{
	char *line;
	
	free(buffer);
	if (!stash)
		return NULL;
	line = stash;
	stash = NULL;
	return (line);
}

static char	*extract(char *s, int end)
{
	size_t	x;
	char	*sub;

	if (!s)
		return (NULL);
	sub = malloc(sizeof(char) * (end + 1));
	if (!sub)
		return (NULL);
	x = 0;
	while (x < end)
		sub[x] = s[x++];
	sub[x] = '\0';
	return (sub);
}