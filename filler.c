/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:23:48 by hluthor           #+#    #+#             */
/*   Updated: 2020/10/02 15:24:05 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <fcntl.h>

void			free_piece(t_filler **filler)
{
    int			i;

    i = 0;
    while ((*filler)->piece[i])
    {
        free((*filler)->piece[i]);
        i++;
    }
    free((*filler)->piece);
}

void			free_filler(t_filler **filler)
{
    int			i;

    i = 0;
    if (filler && *filler)
    {
        if ((*filler)->piece)
            free_piece(filler);
        while ((*filler)->plateau[i])
        {
            free((*filler)->plateau[i]);
            i++;
        }
        free((*filler)->plateau);
        free((*filler));
    }
}

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
    (*filler)->up = (ft_strchr(&(line[4]), 'X') != NULL ? 'X' : 0);
    if (!(*filler)->up)
        (*filler)->up = (ft_strchr(&(line[4]) , 'O') != NULL ? 'O' : '\0');
    if ((*filler)->up && !(*filler)->low)
        (*filler)->low = (*filler)->up == 'O' ? 'X' : 'O';
}

void			init(t_filler **filler, char *line, int fd)
{
    int			i;

    i = 0;
    if ((*filler)->init == 0)
    {
        (*filler)->plateau_width = ft_atoi(&(line[7]));
        (*filler)->plateau_length = ft_atoi((ft_strchr(&line[8], ' ')));
        (*filler)->plateau = (char **) malloc(sizeof(char *) * ((*filler)->plateau_width + 1));
        (*filler)->plateau[(*filler)->plateau_width] = NULL;
    }
    get_next_line(fd, &line);
    free(line);
    while (i < (*filler)->plateau_width)
    {
        get_next_line(fd, &line);
        if ((*filler)->up != 'X' && (*filler)->up != 'O')
            search_up_low(filler, line);
        if ((*filler)->init == 1)
            free((*filler)->plateau[i]);
        (*filler)->plateau[i] = ft_strdup(&line[4]);
        i++;
        free(line);
    }
    (*filler)->init = 1;
}

void			output_coord(int i, int j)
{
    ft_putnbr_fd(i, 1);
    write(1, " ", 1);
    ft_putnbr_fd(j, 1);
    write(1, "\n", 1);
}

void			init_zero(int *a, int *b)
{
    *a = 0;
    *b = 0;
}

void			inc(int *a, int *b)
{
    (*a)++;
    (*b)++;
}

/*int     num_of_star(char **str)
{
    int i;
    int j;
    int num_of_star;

    i = 0;
    num_of_star = 0;
    while (str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] == '*')
                num_of_star++;
            j++;
        }
        i++;
    }
    return num_of_star;
}*/

int				check_valid_length(t_filler **filler, int i, int j, int width)
{
    int			length;
    int			ok;
    int			i1;
    int			j1;
    int			j_copy;

    init_zero(&i1, &ok);
    j_copy = j;
    length = ft_strlen((*filler)->piece[0]);
    while (i1 < width)
    {
        j1 = 0;
        while (j1 < length)
        {
            if ((*filler)->piece[i1][j1] == '*' && ((*filler)->plateau[i][j] == (*filler)->enemy_id || (*filler)->plateau[i][j] == ((*filler)->enemy_id + 32)))
                return 0;
            if ((*filler)->piece[i1][j1] == '*' && ((*filler)->plateau[i][j] == (*filler)->id || (*filler)->plateau[i][j] == (*filler)->id + 32))
                ok++;
            inc(&j1, &j);
        }
        j = j_copy;
        inc(&i, &i1);
    }
    if (ok == 1)
        return 1;
    return 0;
}

int				check_valid_width(t_filler **filler, int i)
{
    int			width;
    int			j;
    int			length;

    width = 0;
    j = 0;
    while ((*filler)->piece[width] != NULL)
        width++;
    if (width > (*filler)->plateau_width - i)
        return 0;
    length = ft_strlen((*filler)->piece[0]);
    while (!check_valid_length(filler, i, j, width))
    {
        j++;
        if (j + length > (*filler)->plateau_length)
            return 0;
    }
    output_coord(i, j);
    return 1;
}

int				move(t_filler **filler)
{
    int			i;
    int			width;
    int			valid;

    width = 0;
    if ((*filler)->up == (*filler)->id)
    {
        i = (*filler)->plateau_width - 1;
        //while (!ft_strchr((*filler)->plateau[i], (*filler)->id) && !ft_strchr((*filler)->plateau[i], (*filler)->id + 32))
            //i--;
        while (i != -1 && (valid = check_valid_width(filler, i)) == 0)
            i--;
        return (valid == 0 ? 0 : 1);
    }
    else
    {
        i = 0;
        while ((*filler)->piece[width] != NULL)
            width++;
        //while (!ft_strchr((*filler)->plateau[i], (*filler)->id) && !ft_strchr((*filler)->plateau[i], (*filler)->id + 32))
            //i++;
        width = (*filler)->plateau_width - width;
        while (i <= width && (valid = check_valid_width(filler, i)) == 0)
            i++;
        return (valid == 0 ? 0 : 1);
    }
}

int				select_move(t_filler **filler)
{
	int			i;

	i = move1(filler);
	if (!i)
		return move(filler);
	return (i);
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
            return (move(filler));
        }
        free(line);
    }
    return 0;
}

t_filler		*inicialize(void)
{
    t_filler	*filler;

    filler = (t_filler *)malloc(sizeof(t_filler));
    filler->up = 0;
    filler->low = 0;
    filler->piece = NULL;
    filler->init = 0;
    return filler;
}

int				main(void)
{
    t_filler	*filler;
    char		*line;
    int			fd;

    //fd = open("file.txt", O_RDONLY);
    fd = 0;
    line = NULL;
    if (get_next_line(fd, &line) < 0 || !line || ft_strncmp(line, "$$$ exec p", 10) || (line[10] != '1' && line[10] != '2'))
        return 0;
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