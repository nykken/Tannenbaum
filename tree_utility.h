#ifndef TREE_UTILITY_H
#define TREE_UTILITY_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "constants.h"


typedef struct {
    char symbol;
    const char *color;
} Cell;

typedef struct {
    int picture_height;
    int picture_width;
    int tree_height;
    int star_height;
    int trunk_height;
    int trunk_width;
    int middle_column;
} Dimensions;

int determine_tree_height(int min, int max);
int is_lucky(int chance);
char pick_star(void);
Dimensions get_dimensions(int tree_height);
Cell **malloc_picture(Dimensions dimensions);
void init_picture(Cell **picture, Dimensions dimensions);
void free_picture(Cell **picture, Dimensions dimensions);
int get_trunk_width(int tree_height);
int get_trunk_height(int tree_height);
int get_star_height(int tree_height);
int get_picture_height(int tree_height);
int get_picture_width(int tree_height);
int check_neighbours(Cell **picture, Dimensions dimensions, char symbol, int row, int column);
int is_ornament(Cell **picture, Dimensions dimensions, int row, int column);
char pick_ornament(void);
const char *pick_color(const char **colors, int size);
const char *pick_ornament_color(void);
void add_star(Cell **picture, Dimensions dimensions);
void add_foliage(Cell **picture, Dimensions dimensions);
void add_trunk(Cell **picture, Dimensions dimensions);
void add_foliage_bottom(Cell **picture, Dimensions dimensions);
void print_tree(Cell **picture, Dimensions dimensions);
Cell **copy_array(Cell **picture, Dimensions dimensions);
void restore_copy(Cell **picture, Cell **copy, Dimensions dimensions);
void add_ground(Cell **picture, Dimensions dimensions);
void prepare_picture(Cell **picture, Dimensions dimensions);

#endif

