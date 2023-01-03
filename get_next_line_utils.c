/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:14:27 by jperinch          #+#    #+#             */
/*   Updated: 2022/09/14 12:47:25 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ms;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	ms = (char *)s;
	while (ms[0] != '\0')
	{
		if (ms[0] == (unsigned char)c)
			return (ms);
		i++;
		ms++;
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*news;
	size_t	i[4];

	i[0] = ft_strlen(s1);
	i[1] = ft_strlen(s2);
	i[2] = 0;
	i[3] = 0;
	news = malloc((i[0] + i[1]) * sizeof(char) + 1);
	if (!news)
		return (NULL);
	while (i[2] < i[0])
	{
		news[i[2]] = s1[i[2]];
		i[2]++;
	}
	free(s1);
	while (i[3] < i[1])
	{
		news[i[2]] = s2[i[3]];
		i[3]++;
		i[2]++;
	}
	news[i[2]] = '\0';
	return (news);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	int		i;
	char	*c;

	len = ft_strlen(s);
	i = 0;
	c = malloc(len * sizeof(char) + 1);
	if (!c)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
