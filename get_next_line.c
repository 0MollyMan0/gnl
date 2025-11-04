/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:41:39 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/04 11:11:55 by anfouger         ###   ########.fr       */
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
		if ((i = strchr(stash)) != NULL)
		{
			x = 0;
			while (x < i+1)
			{
				write(1, stash[i++], 1);
				x++;
			}
		}
	}
	return (NULL);
}