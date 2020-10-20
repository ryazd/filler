/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:23:48 by hluthor           #+#    #+#             */
/*   Updated: 2020/10/20 19:46:51 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <fcntl.h>

void			read_piece(t_filler **filler, int fd, char *line)
{
    int			width;
    int			i;

    i = 0;
    if ((*filler)->piece)
        free_piece(filler);
    width = ft_atoi(&(line[5]));
    (*filler)->piece = (char **)malloc(sizeof(char *) * (width + 1));
    (*filler)->piece[width] = NULL;
    while (i < width)
    {
        free(line);
        get_next_line(fd, &line);
        (*filler)->piece[i] = ft_strdup(line);
        i++;
    }
    free(line);
}

void			search_up_low(t_filler **filler, char *line)
{
    (*filler)->up = (ft_strchr(&(line[4]), 'X') != NULL ? 'X' : '\0');
    if (!(*filler)->up)
        (*filler)->up = (ft_strchr(&(line[4]) , 'O') != NULL ? 'O' : '\0');
    if ((*filler)->up && !(*filler)->low)
        (*filler)->low = (*filler)->up == 'O' ? 'X' : 'O';
}

int				ft_strchrpos(char *str, char chr)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == chr)
			return i;
		i++;
	}
	return -1;
}

int				read_plateau(t_filler **filler, int fd)
{
    char		*line;

    while (get_next_line(fd, &line) > 0)
    {
        if (!ft_strncmp(line, "Plateau ", 8))
            init(filler, line, fd);
        if (!ft_strncmp(line, "Piece ", 6))
        {
            read_piece(filler, fd, line);
            return (select_move(filler));
        }
        free(line);
    }
    return 0;
}

int				main(void)
{
    t_filler	*filler;
    char		*line;
    int			fd;

    fd = 0;
    line = NULL;
    if (get_next_line(fd, &line) < 0 || !line || ft_strncmp(line, "$$$ exec p", 10) || (line[10] != '1' && line[10] != '2'))
    {
    	free(line);
		return 0;
	}
    filler = inicialize();
    filler->id = line[10] == '1' ? 'O' : 'X';
    filler->enemy_id = filler->id == 'X' ? 'O' : 'X';
    free(line);
    while (1)
    {
            if (read_plateau(&filler, fd) == 0) {
                ft_putstr("0 0\n");
                break;
            }
    }
    free_filler(&filler);
    return (0);
}
