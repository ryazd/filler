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
}               t_filler;

#endif //FILLER1_FILLER_H
