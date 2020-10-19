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

void 			free_hotmap(t_filler **filler)
{
	int 		i;

	i = 0;
	while (i < (*filler)->plateau_width)
	{
		free((*filler)->hot_map[i]);
		i++;
	}
	free((*filler)->hot_map);
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
        if ((*filler)->hot_map)
        	free_hotmap(filler);
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

void 			init_pos(t_filler **filler)
{
	int			i;
	char 		my_id;
	char 		enemy_id;

	my_id = (*filler)->id;
	enemy_id = (*filler)->enemy_id;
	i = 0;
	while ((*filler)->plateau[i])
	{
		if ((*filler)->my_pos == -1)
			(*filler)->my_pos = ft_strchrpos((*filler)->plateau[i], my_id);
		if ((*filler)->enemy_pos == -1)
			(*filler)->enemy_pos = ft_strchrpos((*filler)->plateau[i], enemy_id);
		if ((*filler)->my_pos != -1 && (*filler)->enemy_pos != -1)
			break;
		i++;
	}
}

void			init_alloc(t_filler **filler, char *line)
{
	(*filler)->plateau_width = ft_atoi(&(line[7]));
	(*filler)->plateau_length = ft_atoi((ft_strchr(&line[8], ' ')));
	(*filler)->plateau = (char **) malloc(sizeof(char *) * ((*filler)->plateau_width + 1));
	(*filler)->plateau[(*filler)->plateau_width] = NULL;
}

void			init_hot_map(t_filler **filler)
{
	int			i;

	i = 0;
	while (i < (*filler)->plateau_width)
	{
		(*filler)->hot_map[i] = (int *)malloc(sizeof(int) * (*filler)->plateau_length);
		i++;
	}
}

void 			hot_map_by_2(t_filler **filler)
{
	int 		i;
	int 		j;

	i = 0;
	while (i < (*filler)->plateau_width)
	{
		j = 0;
		while (j < (*filler)->plateau_length)
		{
			(*filler)->hot_map[i][j] = -2;
			j++;
		}
		i++;
	}
}

int 			distance(int i, int j, int i_pl, int j_pl)
{
	i = i > i_pl ? i - i_pl : i_pl - i;
	j = j > j_pl ? j - j_pl : j_pl - j;
	if (i == j)
		return i;
	return i > j ? i : j;
}

int 			htz(t_filler **filler, int i_pl, int j_pl)
{
	int 		k1;
	int			k2;
	int 		i;
	int 		j;

	i = 0;
	k1 = -1;
	k2 = -1;
	while (i < (*filler)->plateau_width)
	{
		j = 0;
		while (j < (*filler)->plateau_length)
		{
			if ((*filler)->hot_map[i][j] == 0)
				k2 = distance(i, j, i_pl, j_pl);
			if (k1 == -1 || k1 > k2)
				k1 = k2;
			j++;
		}
		i++;
	}
	return k1;
}

void 			hot_map_zap(t_filler **filler)
{
	int			i;
	int 		j;

	i = 0;
	while (i < (*filler)->plateau_width)
	{
		j = 0;
		while (j < (*filler)->plateau_length)
		{
			if ((*filler)->plateau[i][j] == '.')
				(*filler)->hot_map[i][j] = htz(filler, i, j);
			j++;
		}
		i++;
	}
}

void 			hot_map(t_filler **filler)
{
	int 		i;
	int 		j;

	i = 0;
	if ((*filler)->init == 0)
	{
		(*filler)->hot_map = (int **) malloc(sizeof(int *) * (*filler)->plateau_width);
		init_hot_map(filler);
	}
	hot_map_by_2(filler);
	while ((*filler)->plateau[i])
	{
		j = 0;
		while ((*filler)->plateau[i][j])
		{
			if ((*filler)->plateau[i][j] == (*filler)->id)
				(*filler)->hot_map[i][j] = -1;
			if ((*filler)->plateau[i][j] == (*filler)->enemy_id || (*filler)->plateau[i][j] == (*filler)->enemy_id + 32)
				(*filler)->hot_map[i][j] = 0;
			j++;
		}
		i++;
	}
	hot_map_zap(filler);
}

void			init(t_filler **filler, char *line, int fd)
{
    int			i;

    i = 0;
    if ((*filler)->init == 0)
    	init_alloc(filler, line);
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
    if ((*filler)->init == 0)
    	init_pos(filler);
    hot_map(filler);
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
    return (ok == 1 ? 1 : 0);
}

int 			check_valid_width1(t_filler **filler, int i)
{
	int			width;
	int			j;
	int			length;

	width = 0;
	while ((*filler)->piece[width] != NULL)
		width++;
	if (width > (*filler)->plateau_width - i)
		return 0;
	length = ft_strlen((*filler)->piece[0]);
	j = (*filler)->plateau_length - length;
	while (!check_valid_length(filler, i, j, width))
	{
		j--;
		if (j == -1)
			return 0;
	}
	output_coord(i, j);
	return 1;
}

int				check_valid_width(t_filler **filler, int i, int spec)
{
    int			width;
    int			j;
    int			length;

    if (spec == 1)
		return (check_valid_width1(filler, i));
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

int				move(t_filler **filler, int spec)
{
    int			i;
    int			width;
    int			valid;

    width = 0;
    if ((*filler)->up == (*filler)->id)
    {
        i = (*filler)->plateau_width - 1;
        while (i != -1 && (valid = check_valid_width(filler, i, spec)) == 0)
            i--;
        return (valid == 0 ? 0 : 1);
    }
    else
    {
        i = 0;
        while ((*filler)->piece[width] != NULL)
            width++;
        width = (*filler)->plateau_width - width;
        while (i <= width && (valid = check_valid_width(filler, i, spec)) == 0)
            i++;
        return (valid == 0 ? 0 : 1);
    }
}

int 			num_of_score(t_filler **filler, int i, int j, int width)
{
	int 		score;
	int 		pos_i;
	int 		pos_j;
	int 		length;

	length = ft_strlen((*filler)->piece[0]);
	init_zero(&pos_i, &score);
	while (pos_i < width)
	{
		pos_j = 0;
		while (pos_j < length)
		{
			if ((*filler)->piece[pos_i][pos_j] == '*' &&
			(*filler)->hot_map[i + pos_i][j + pos_j] != -1)
				score += (*filler)->hot_map[i + pos_i][j + pos_j];
			pos_j++;
		}
		pos_i++;
	}
	return score;
}

void 			add_coord(t_filler **filler, int i, int j)
{
	(*filler)->coord_j = j;
	(*filler)->coord_i = i;
}

int 			move_hot(t_filler **filler, int k2, int width, int length)
{
	int			i;
	int 		j;
	int 		k1;

	k1 = -1;
	i = 0;
	while (i + width <= (*filler)->plateau_width)
	{
		j = 0;
		while (j + length <= (*filler)->plateau_length)
		{
			if (check_valid_length(filler, i, j, width) == 1)
			{
				k2 = num_of_score(filler, i, j, width);
				if (k1 == -1 || k1 > k2)
				{
					k1 = k2;
					add_coord(filler, i, j);
				}
			}
			j++;
		}
		i++;
	}
	return (k1 == -1 ? 0 : 1);
}

int				select_move(t_filler **filler)
{
	int			i;
	int 		c;
	int			width;
	int			length;

	i = 0;
	c = -1;
	length = ft_strlen((*filler)->piece[0]);
	width = 0;
	while ((*filler)->piece[width] != NULL)
		width++;
	i = move_hot(filler, c, width, length);
	if (i == 1)
		output_coord((*filler)->coord_i, (*filler)->coord_j);
	if (!i && ((*filler)->up == (*filler)->id || ((*filler)->low == (*filler)->id)) &&
	(*filler)->my_pos < (*filler)->enemy_pos)
		i = move(filler, 1);
	if (!i)
		return move(filler, 0);
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
            return (select_move(filler));
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
    filler->enemy_pos = -1;
    filler->my_pos = -1;
    filler->coord_i = -1;
    filler->coord_j = -1;
    return filler;
}

int				main(void)
{
    t_filler	*filler;
    char		*line;
    int			fd;

    //fd = open("file1.txt", O_RDONLY);
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