//
// Created by Horpe Luthor on 10/2/20.
//

#ifndef FILLER1_FILLER_H
#define FILLER1_FILLER_H

#include "get_next_line.h"
#include <unistd.h>

typedef struct  s_filler
{
    char        id;
    int         init;
    char        **plateau;
    int         plateau_length;
    int         plateau_width;
    char        up;
    char        low;
    char        enemy_id;
    char        **piece;
    int			my_pos;
    int 		enemy_pos;
    int 		**hot_map;
    int 		coord_i;
    int 		coord_j;
}               t_filler;

void			free_piece(t_filler **filler);											///
void			free_filler(t_filler **filler);											///
void			read_piece(t_filler **filler, int fd, char *line);
void			search_up_low(t_filler **filler, char *line);
int				ft_strchrpos(char *str, char chr);
void 			init_pos(t_filler **filler);											///
void			init(t_filler **filler, char *line, int fd);							///
void			output_coord(int i, int j);
void			init_zero(int *a, int *b);												///
void			inc(int *a, int *b);
int				check_valid_length(t_filler **filler, int i, int j, int width);
int 			check_valid_width1(t_filler **filler, int i);
int				check_valid_width(t_filler **filler, int i, int spec);
int				move(t_filler **filler, int spec);
int				select_move(t_filler **filler);
int				read_plateau(t_filler **filler, int fd);
t_filler		*inicialize(void);														///
int 			move_hot(t_filler **filler, int k2, int width, int length);
void 			add_coord(t_filler **filler, int i, int j);
int 			num_of_score(t_filler **filler, int i, int j, int width);
void 			hot_map(t_filler **filler);												///
void 			hot_map_zap(t_filler **filler);											///
int 			htz(t_filler **filler, int i_pl, int j_pl);								///
int 			distance(int i, int j, int i_pl, int j_pl);
void 			hot_map_by_2(t_filler **filler);										///
void			init_hot_map(t_filler **filler);										///
void			init_alloc(t_filler **filler, char *line);								///
void 			free_hotmap(t_filler **filler);											///

#endif //FILLER1_FILLER_H
