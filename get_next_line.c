/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:12:57 by jperinch          #+#    #+#             */
/*   Updated: 2023/01/02 13:10:09 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*extra(char *str, int flag)
{
	static char	*str2;
	int			len;

	if (flag == 1)
	{
		if (str)
		{
			len = wordremover(str);
			str2 = (char *)malloc((sizeof(char) * (len) + 1));
			str2[len] = '\0';
			next(str, str2, len);
			return (ft_strdup(str));
		}
	}
	else if (str2)
	{
		if (flag == 4)
		{
			free(str2);
			str2 = NULL;
			return (NULL);
		}
		return (ft_strdup(str2));
	}
	return (NULL);
}

char	*next_line(int fd, int count)
{
	char	*str;
	char	*str1;

	str = extra(NULL, 3);
	if (str)
		extra(NULL, 4);
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
	str = extra(c, 1);
	free(c);
	if ((str && str[0] == '\0'))
	{
		free(str);
		return (NULL);
	}
	return (str);
}
int main()
{
    int f;
    f = open("in", O_RDONLY);
    char *str;
    int i =0;
    // while(1)
    //     {
            str = get_next_line(f);
            printf("%s",str );
            // if(!str)
            //     break ;
            free(str);
			 str = get_next_line(f);
            printf("%s",str );
			  free(str);
			  	 str = get_next_line(f);
            printf("%s",str );
			  free(str);
			  	 str = get_next_line(f);
            printf("%s",str );
			  free(str);
            i++;
        // }
}