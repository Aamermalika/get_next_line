/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamer <maamer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:30:46 by maamer            #+#    #+#             */
/*   Updated: 2021/12/21 12:38:57 by maamer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*print_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc((i + 2) * sizeof(char));
	ft_strlcpy(line, str, i + 2);
	line[i + 2] = '\0';
	return (line);
}

char	*lba9i(char *str)
{
	int		j;
	char	*p;

	j = 0;
	while (str[j] != '\n' && str[j] != '\0')
		j++;
	p = str;
	str = ft_substr(str, j + 1, ft_strlen(str) - j);
	free (p);
	return (str);
}

char	*readfile(int fd)
{
	static char	*str;
	char		*line;
	char		*buf;
	int			read_size;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	read_size = 1;
	while (read_size && !(ft_strchr(str, '\n')))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			free (buf);
			return (0);
		}
		buf[read_size] = '\0';
		str = ft_strjoin(str, buf);
	}
	free (buf);
	if (read_size == 0 && (!str || !str[0]))
		return (0);
	line = print_line(str);
	str = lba9i(str);
	return (line);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	return (readfile(fd));
}
