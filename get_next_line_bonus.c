/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamer <maamer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:29:33 by maamer            #+#    #+#             */
/*   Updated: 2021/12/21 14:15:47 by maamer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[1024];
	char		*line;
	char		*buf;
	int			read_size;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	read_size = 1;
	while (read_size && !(ft_strchr(str[fd], '\n')))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			free (buf);
			return (0);
		}
		buf[read_size] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
	}
	free (buf);
	if (read_size == 0 && !str[fd])
		return (0);
	line = print_line(str[fd]);
	str[fd] = lba9i(str[fd]);
	return (line);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= 1024)
		return (NULL);
	return (readfile(fd));
}
