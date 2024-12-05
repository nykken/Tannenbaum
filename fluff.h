#ifndef FLUFF_H
#define FLUFF_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tree_utility.h"

typedef struct {
    char *primary;
    char *secondary;
} Colors;

void add_fluff(Cell **picture, Dimensions dimensions);
int include_critter(Dimensions dimensions);
int include_gift(Dimensions dimensions);
void add_owl(Cell **picture, Dimensions dimensions);
int include_owl(Dimensions dimensions);
void add_critter(Cell **picture, Dimensions dimensions);
void add_gift(Cell **picture, Dimensions dimensions);
void add_small_gift(Cell **picture, Dimensions dimensions, Colors colors);
void add_large_gift(Cell **picture, Dimensions dimensions, Colors colors);
Colors pick_gift_colors(char *gift_colors[6]);

#endif

