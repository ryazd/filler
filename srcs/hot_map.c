/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:03:24 by hluthor           #+#    #+#             */
/*   Updated: 2020/10/26 20:38:07 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void			init_hot_map(t_filler **filler)
{
	int			i;

	i = 0;
	(*filler)->hot_map = (int **)malloc(sizeof(int *) *
			(*filler)->plateau_width);
	while (i < (*filler)->plateau_width)
	{
		(*filler)->hot_map[i] = (int *)malloc(sizeof(int) *
				(*filler)->plateau_length);
		i++;
	}
}

void			hot_map_by_2(t_filler **filler)
{
	int			i;
	int			j;

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

int				htz(t_filler **filler, int i_pl, int j_pl)
{
	int			k1;
	int			k2;
	int			i;
	int			j;

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
	return (k1);
}

void			hot_map_zap(t_filler **filler)
{
	int			i;
	int			j;

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

void			hot_map(t_filler **filler)
{
	int			i;
	int			j;

	i = 0;
	if ((*filler)->init == 0)
		init_hot_map(filler);
	hot_map_by_2(filler);
	while ((*filler)->plateau[i])
	{
		j = 0;
		while ((*filler)->plateau[i][j])
		{
			if ((*filler)->plateau[i][j] == (*filler)->id)
				(*filler)->hot_map[i][j] = -1;
			if ((*filler)->plateau[i][j] == (*filler)->enemy_id ||
					(*filler)->plateau[i][j] == (*filler)->enemy_id + 32)
				(*filler)->hot_map[i][j] = 0;
			j++;
		}
		i++;
	}
	hot_map_zap(filler);
}
