#ifndef SNOW_H
#define SNOW_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tree_utility.h"

int is_bg_snowflake(Cell **picture, Dimensions dimensions, int row, int column);
void add_snowflakes(Cell **picture, Dimensions dimensions, int in_foreground);
void clear_snowflakes(Cell **picture, Dimensions dimensions);
void make_it_snow(Cell **picture, Cell ** copy, Dimensions dimensions, int in_foreground);
void acid_snow(Cell **picture, Dimensions dimensions);

#endif


