/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:42:02 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/04 12:30:28 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len_s2;
	size_t			len_s1;
	char			*new;
	int				i;
	int				j;

	if (!s1)
	{
		s1 = malloc(sizeof(char)*1);
		s1[0] = '\0';
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (len_s2 + len_s1 + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		new[j++] = s1[j];
	while (s2[i])
		new[j + i] = s2[i++];
	new[j] = '\0';
	return (new);
}

char	*ft_substr(const char *s, unsigned int start)
{
	size_t	slen;
	size_t	x;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	sub = malloc(sizeof(char) * (slen - start + 1));
	if (!sub)
		return (NULL);
	x = 0;
	while (s[start + x])
		sub[x++] = s[start + x];
	sub[x] = '\0';
	return (sub);
}