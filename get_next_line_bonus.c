/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:12:57 by jperinch          #+#    #+#             */
/*   Updated: 2022/09/14 12:51:35 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	wordremover(char *str)
{
	int	i;

	i = 0;
	while (*str != '\n' && *str != '\0')
		str++;
	if (*str == '\n')
		str++;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	next(char *str, char *str2, int size)
{
	int	len;

	len = 0;
	while (*str != '\n' && *str != '\0')
		str++;
	if (*str == '\n')
		str++;
	while (len < size)
	{
		str2[len] = str[0];
		str[0] = '\0';
		str++;
		len++;
	}
	str2[len] = '\0';
}

char	*extra(char *str, int flag, int fd)
{
	static char	*str2[1048576];
	int			len;

	if (flag == 1)
	{
		if (str)
		{
			len = wordremover(str);
			str2[fd] = (char *)malloc((sizeof(char) * (len) + 1));
			str2[fd][len] = '\0';
			next(str, str2[fd], len);
			return (ft_strdup(str));
		}
	}
	else if (str2[fd])
	{
		if (flag == 4)
		{
			free(str2[fd]);
			str2[fd] = NULL;
			return (NULL);
		}
		return (ft_strdup(str2[fd]));
	}
	return (NULL);
}

char	*next_line(int fd, int count)
{
	char	*str;
	char	*str1;

	str = extra(NULL, 3, fd);
	if (str)
		extra(NULL, 4, fd);
	str1 = (char *)malloc((sizeof(char) * (BUFFER_SIZE) + 1));
	while ((!(ft_strchr(str, '\n')) && count > 0))
	{
		count = read(fd, str1, BUFFER_SIZE);
		if (count == -1)
		{
			free(str1);
			return (NULL);
		}
		str1[count] = '\0';
		str = ft_strjoin(str, str1);
	}
	if (count == 0 && str[0] == '\0')
	{
		free(str);
		str = NULL;
	}
	free(str1);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*c;
	char	*str;
	int		count;

	count = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	c = next_line(fd, count);
	str = extra(c, 1, fd);
	free(c);
	if ((str && str[0] == '\0'))
	{
		free(str);
		return (NULL);
	}
	return (str);
}
// int main()
// {
//     int f;
//     f = open("txt.txt", O_RDONLY);
//     char *str;
//     int i =0;
//     while(1)
//         {
//             str = get_next_line(f);
//             printf("%s",str );
//             free(str);
//             if(!str)
//                 break ;
//             i++;
//         }
// }