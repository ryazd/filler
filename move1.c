/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:14:44 by hluthor           #+#    #+#             */
/*   Updated: 2020/10/20 19:15:31 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
