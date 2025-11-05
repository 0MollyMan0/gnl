/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:42:02 by anfouger          #+#    #+#             */
/*   Updated: 2025/11/05 10:43:35 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr_i(const char *s, int c)
{
    int i;

    i = 0;
    if (!s)
        return (-1);
    while (s[i])
    {
        if (s[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

char	*ft_strjoin(char *s1, char const *s2)
{
    char    *new;
    int     i = 0;
    int     j = 0;

    if (!s2)
        return (s1);
    if (!s1)
    {
        s1 = malloc(1);
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new)
        return (NULL);
    while (s1[i])
        new[i] = s1[i++];
    while (s2[j])
        new[i + j] = s2[j++];
    new[i + j] = '\0';
    free(s1);
    return (new);
}

char	*ft_substr(char *s, unsigned int start)
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
		sub[x] = s[start + x++];
	sub[x] = '\0';
    free(s);
	return (sub);
}