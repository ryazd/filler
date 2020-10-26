/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:59:15 by hluthor           #+#    #+#             */
/*   Updated: 2020/10/26 21:42:26 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int				checker(char piece, char plateau, t_filler **filler, int i)
{
	if (i == 1)
	{
		if (piece == '*' && (plateau == (*filler)->enemy_id ||
					plateau == ((*filler)->enemy_id + 32)))
			return (0);
		else
			return (1);
	}
	else
	{
		if (piece == '*' && (plateau == (*filler)->id
					|| plateau == (*filler)->id + 32))
			return (1);
	}
	return (0);
}

void			inc(int *a, int *b)
{
	(*a)++;
	(*b)++;
}

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

void			free_hotmap(t_filler **filler)
{
	int			i;

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
