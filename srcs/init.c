/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluthor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:08:39 by hluthor           #+#    #+#             */
/*   Updated: 2020/10/26 21:20:45 by hluthor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

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
	return (filler);
}

void			init_zero(int *a, int *b)
{
	*a = 0;
	*b = 0;
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

void			init_alloc(t_filler **filler, char *line)
{
	(*filler)->plateau_width = ft_atoi(&(line[7]));
	(*filler)->plateau_length = ft_atoi((ft_strchr(&line[8], ' ')));
	(*filler)->plateau = (char **)malloc(sizeof(char *)
			* ((*filler)->plateau_width + 1));
	(*filler)->plateau[(*filler)->plateau_width] = NULL;
}

void			init_pos(t_filler **filler)
{
	int			i;
	char		my_id;
	char		enemy_id;

	my_id = (*filler)->id;
	enemy_id = (*filler)->enemy_id;
	i = 0;
	while ((*filler)->plateau[i])
	{
		if ((*filler)->my_pos == -1)
			(*filler)->my_pos = ft_strchrpos((*filler)->plateau[i], my_id);
		if ((*filler)->enemy_pos == -1)
			(*filler)->enemy_pos = ft_strchrpos((*filler)->
					plateau[i], enemy_id);
		if ((*filler)->my_pos != -1 && (*filler)->enemy_pos != -1)
			break ;
		i++;
	}
}
