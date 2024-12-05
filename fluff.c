#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tree_utility.h"
#include "constants.h"
#include "fluff.h"
#include "error_handling.h"

void add_fluff(Cell **picture, Dimensions dimensions)
{
    if (include_critter(dimensions))
    {   
        add_critter(picture, dimensions);
    }
    if (include_gift(dimensions))
    {
        add_gift(picture, dimensions);
    }
    if (include_owl(dimensions))
    {
        add_owl(picture, dimensions);
    }
}

int include_critter(Dimensions dimensions)
{
    if (dimensions.tree_height == 17)
    {
        if (is_lucky(5))
        {
            return 1;
        }
    }
    return 0;  
}

int include_gift(Dimensions dimensions)
{
    if (dimensions.trunk_height >= 3)
    {
        if (is_lucky(3))
        {
            return 1;
        }
    }
    return 0;
}

void add_gift(Cell **picture, Dimensions dimensions)
{
    char *gift_colors[6] = {BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW,
                        BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN};
    Colors colors = pick_gift_colors(gift_colors);

    if (dimensions.trunk_height == 3)
    {
        add_small_gift(picture, dimensions, colors);
    }
    else if (dimensions.trunk_height == 4)
    {
        add_large_gift(picture, dimensions, colors); 
    }
    else
    /* for debugging purposes */
    {
        size_error("Invalid trunk height for gift");
    }
    return;
}

Colors pick_gift_colors(char *gift_colors[6])
{
    int secondary_index, primary_index;
    char *primary;
    char *secondary;
    Colors colors;

    primary_index = rand() % 6;
    primary = gift_colors[primary_index];

    do
    {
        secondary_index = rand() % 6;
    } while (secondary_index == primary_index);

    secondary = gift_colors[secondary_index];
    colors.primary = primary;
    colors.secondary = secondary;
    return colors;
}

void add_small_gift(Cell **picture, Dimensions dimensions, Colors colors)
{
    int end_row = dimensions.picture_height - 1;
    int start_row = end_row - 1;
    int start_column = dimensions.picture_width - 9;

    /* first row */
    picture[start_row][start_column + 1].symbol = '_';
    picture[start_row][start_column + 1].color = colors.primary;
    picture[start_row][start_column + 2].symbol = '*';
    picture[start_row][start_column + 2].color = colors.secondary;
    picture[start_row][start_column + 3].symbol = '_';
    picture[start_row][start_column + 3].color = colors.primary;

    /* second row */
    picture[end_row][start_column].symbol = '|';
    picture[end_row][start_column].color = colors.primary;
    picture[end_row][start_column + 1].symbol = '_';
    picture[end_row][start_column + 1].color = colors.primary;
    picture[end_row][start_column + 2].symbol = '|';
    picture[end_row][start_column + 2].color = colors.secondary;
    picture[end_row][start_column + 3].symbol = '_';
    picture[end_row][start_column + 3].color = colors.primary;
    picture[end_row][start_column + 4].symbol = '|';
    picture[end_row][start_column + 4].color = colors.primary;
}

void add_large_gift(Cell **picture, Dimensions dimensions, Colors colors)
{
    int start_row = dimensions.picture_height - 3;
    int start_column = 3;
    int i;
    int j;

    /* first row */
    picture[start_row][start_column + 1].symbol = '_';
    picture[start_row][start_column + 1].color = colors.primary;
    picture[start_row][start_column + 2].symbol = '~';
    picture[start_row][start_column + 2].color = colors.secondary;
    picture[start_row][start_column + 3].symbol = '*';
    picture[start_row][start_column + 3].color = colors.secondary;
    picture[start_row][start_column + 4].symbol = '~';
    picture[start_row][start_column + 4].color = colors.secondary;
    picture[start_row][start_column + 5].symbol = '_';
    picture[start_row][start_column + 5].color = colors.primary;

    /* other rows */
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (j % 3 == 0)
            {
                picture[start_row + i + 1][start_column + j].symbol = '|';
            }
            else
            {
                picture[start_row + i + 1][start_column + j].symbol = '_';
            }
            if ((j == 3) || (i == 0 && j % 3 != 0))
            {
                picture[start_row + i + 1][start_column + j].color = colors.secondary;   
            }
            else
            {
                picture[start_row + i + 1][start_column + j].color = colors.primary;
            }
        }
    }
    return;
}

int include_owl(Dimensions dimensions)
{
    if (dimensions.tree_height > 14)
    {
        if (is_lucky(3))
        {
            return 1;
        }
    }
    return 0;
}

void add_critter(Cell **picture, Dimensions dimensions)
{
    char *pompom_color = BRIGHT_WHITE;
    char *hat_color = BRIGHT_RED;
    char *gift_color = BRIGHT_MAGENTA;
    char *gift_secondary = BRIGHT_YELLOW;
    char *critter_color = WHITE;
    char *eye_color = WHITE;
    char *mouth_color = WHITE;
    char *cloak_color = BRIGHT_RED;

    if (dimensions.tree_height != 17)
    /* for debugging purposes */
    {
        size_error("Invalid height for critter");
    }
    else
    {
        /* pompom */
        picture[1][4].symbol = 'o';
        picture[1][4].color = pompom_color;

        /* hat */
        picture[2][3].symbol = '/';
        picture[2][3].color = hat_color;
        picture[2][4].color = BRIGHT_CYAN; /*whitespace*/
        picture[2][5].symbol = '\\';
        picture[2][5].color = hat_color;

        picture[3][2].symbol = '/';
        picture[3][2].color = hat_color;
        picture[3][3].symbol = '_';
        picture[3][3].color = hat_color;
        picture[3][4].symbol = '_';
        picture[3][4].color = hat_color;
        picture[3][5].symbol = '_';
        picture[3][5].color = hat_color;
        picture[3][6].symbol = '\\';
        picture[3][6].color = hat_color;

        /* face */
        picture[4][0].symbol = '{';
        picture[4][0].color = critter_color;
        picture[4][1].color = BRIGHT_CYAN; /*whitespace*/
        picture[4][2].symbol = 'o';
        picture[4][2].color = eye_color;
        picture[4][3].color = BRIGHT_CYAN; /*whitespace*/
        picture[4][4].symbol = '_';
        picture[4][4].color = mouth_color;
        picture[4][5].color = BRIGHT_CYAN; /*whitespace*/
        picture[4][6].symbol = 'o';
        picture[4][6].color = eye_color;
        picture[4][7].symbol = '}';
        picture[4][7].color = critter_color;

        /* top of gift */
        picture[4][9].symbol = '_';
        picture[4][9].color = gift_color;
        picture[4][10].symbol = '*';
        picture[4][10].color = gift_secondary;
        picture[4][11].symbol = '_';
        picture[4][11].color = gift_color;

        /* upper body */
        picture[5][1].symbol = '/';
        picture[5][1].color = cloak_color;
        picture[5][2].color = BRIGHT_CYAN; /*whitespace*/
        picture[5][3].symbol = '>';
        picture[5][3].color = critter_color;
        picture[5][4].color = BRIGHT_CYAN; /*whitespace*/
        picture[5][5].color = BRIGHT_CYAN; /*whitespace*/
        picture[5][6].symbol = '|';
        picture[5][6].color = cloak_color;
        picture[5][7].symbol = '>';
        picture[5][7].color = critter_color;

        /* bottom of gift */
        picture[5][8].symbol = '|';
        picture[5][8].color = gift_color;
        picture[5][9].symbol = '_';
        picture[5][9].color = gift_color;
        picture[5][10].symbol = '|';
        picture[5][10].color = gift_secondary;
        picture[5][11].symbol = '_';
        picture[5][11].color = gift_color;
        picture[5][12].symbol = '|';
        picture[5][12].color = gift_color;

        /* lower body */
        picture[6][0].symbol = '/';
        picture[6][0].color = cloak_color;
        picture[6][1].symbol = '_';
        picture[6][1].color = cloak_color;
        picture[6][2].color = BRIGHT_CYAN; /*whitespace*/
        picture[6][3].symbol = '_';
        picture[6][3].color = cloak_color;
        picture[6][4].symbol = '_';
        picture[6][4].color = cloak_color;
        picture[6][5].color = BRIGHT_CYAN; /*whitespace*/
        picture[6][6].symbol = '|';
        picture[6][6].color = cloak_color;

        /* legs */
        picture[7][2].symbol = 'U';
        picture[7][2].color = critter_color;
        picture[7][5].symbol = 'U';
        picture[7][5].color = critter_color;
    }
}

void add_owl(Cell **picture, Dimensions dimensions)
{
    int start_row, start_column;
    const char *owl_color = BRIGHT_WHITE;
    const char *eye_color = WHITE;
    const char *beak_color = YELLOW;

    start_row = dimensions.picture_height - 3;
    start_column = dimensions.middle_column + 5;

    /* ears */
    picture[start_row][start_column + 1].symbol = '{';
    picture[start_row][start_column + 1].color = owl_color;
    picture[start_row][start_column + 2].symbol = '\\';
    picture[start_row][start_column + 2].color = owl_color;
    picture[start_row][start_column + 3].symbol = '_';
    picture[start_row][start_column + 3].color = owl_color;
    picture[start_row][start_column + 4].symbol = '_';
    picture[start_row][start_column + 4].color = owl_color;
    picture[start_row][start_column + 5].symbol = '/';
    picture[start_row][start_column + 5].color = owl_color;
    picture[start_row][start_column + 6].symbol = '}';
    picture[start_row][start_column + 6].color = owl_color;

    /* face */
    picture[start_row + 1][start_column + 1].symbol = '(';
    picture[start_row + 1][start_column + 1].color = owl_color;
    picture[start_row + 1][start_column + 2].symbol = '\'';
    picture[start_row + 1][start_column + 2].color = eye_color;
    picture[start_row + 1][start_column + 3].color = BRIGHT_CYAN; /*whitespace*/
    picture[start_row + 1][start_column + 4].symbol = 'v';
    picture[start_row + 1][start_column + 4].color = beak_color;
    picture[start_row + 1][start_column + 5].symbol = '\'';
    picture[start_row + 1][start_column + 5].color = eye_color;
    picture[start_row + 1][start_column + 6].symbol = ')';
    picture[start_row + 1][start_column + 6].color = owl_color;

    /* body */
    picture[start_row + 2][start_column].symbol = '(';
    picture[start_row + 2][start_column].color = owl_color;
    picture[start_row + 2][start_column + 1].symbol = ')';
    picture[start_row + 2][start_column + 1].color = owl_color;
    picture[start_row + 2][start_column + 2].symbol = '_';
    picture[start_row + 2][start_column + 2].color = owl_color;
    picture[start_row + 2][start_column + 3].symbol = '_';
    picture[start_row + 2][start_column + 3].color = owl_color;
    picture[start_row + 2][start_column + 4].symbol = '_';
    picture[start_row + 2][start_column + 4].color = owl_color;
    picture[start_row + 2][start_column + 5].symbol = '_';
    picture[start_row + 2][start_column + 5].color = owl_color;
    picture[start_row + 2][start_column + 6].symbol = ')';
    picture[start_row + 2][start_column + 6].color = owl_color;
}

