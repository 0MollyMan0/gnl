/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:41:39 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/04 12:11:30 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *stash;
	char *buffer;
	int i;
	int x;

	if (fd < 0 || !buffer || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		stash = ft_strjoin(stash, buffer);
		if ((i = strchr(stash, '\n')) != NULL)
		{
			x = 0;
			while (x < i + 1)
				write(1, stash[x++], 1);
			stash = substr(stash, i);
		}
	}
	else if (read(fd, buffer, BUFFER_SIZE) == 0)
	{
		x = 0;
		while (stash[x])
			write(1, stash[x++], 1);
	}
	return (NULL);
}