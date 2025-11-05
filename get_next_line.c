/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:41:39 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/05 10:42:00 by anfouger         ###   ########.fr       */
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
		buffer[BUFFER_SIZE] = '\0';
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
	{
		free(buffer);
		if (!stash)
			return NULL;
		line = stash;
		free(stash);
		stash = NULL;
		return (line);
	}
	return (NULL);
}

static void extract(){}