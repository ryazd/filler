/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:02:17 by hluthor           #+#    #+#             */
/*   Updated: 2019/10/15 19:40:26 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int		zap(char **str, int read_size, char **line, int p)
{
	char		*s;
	char		*s1;

	if (read_size == -1)
		return (-1);
	if (read_size == 0 && p == 0 && ft_strstr(*line, *str))
		return (0);
	s = *str;
	if ((s1 = ft_strchr(s, '\n')) != NULL)
	{
		*s1 = '\0';
		*line = ft_strdup(*str);
		*str = ft_strdup(s1 + 1);
	}
	else
		*line = ft_strdup(*str);
	free(s);
	if (!line || !*str)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			read_size;
	static char	*str[255];
	char		*s;
	int			p;

	if (fd < 0 || !line)
		return (-1);
	p = 0;
	while ((read_size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_size] = '\0';
		s = str[fd];
		str[fd] = ft_strjoin(str[fd], buff);
		if (s != NULL)
			free(s);
		if (!str[fd])
			return (-1);
		if (ft_strchr(str[fd], '\n'))
			break ;
		p++;
	}
	return (zap(&(str[fd]), read_size, line, p));
}
