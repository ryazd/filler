/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:16:35 by hluthor           #+#    #+#             */
/*   Updated: 2020/10/20 19:18:11 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 			distance(int i, int j, int i_pl, int j_pl)
{
	i = i > i_pl ? i - i_pl : i_pl - i;
	j = j > j_pl ? j - j_pl : j_pl - j;
	if (i == j)
		return i;
	return i > j ? i : j;
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

void			output_coord(int i, int j)
{
    ft_putnbr_fd(i, 1);
    write(1, " ", 1);
    ft_putnbr_fd(j, 1);
    write(1, "\n", 1);
}
