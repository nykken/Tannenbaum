#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "tree_utility.h"
#include "snow.h"


void add_snowflakes(Cell **picture, Dimensions dimensions, int in_foreground)
{
    const char *snowflake_colors[4] = {WHITE, CYAN, BRIGHT_WHITE, BRIGHT_CYAN};
    const char *color;
    int i, j;

    if (in_foreground)
    {
        for (i = 0; i < dimensions.picture_height; i++)
        {
            for (j = 0; j < dimensions.picture_width; j++)
            {   
                if (check_neighbours(picture, dimensions, '*', i, j) == 0)
                {
                    if (is_lucky(7))
                    {     
                        color = pick_color(snowflake_colors, 4);
                        picture[i][j].symbol = '*';
                        picture[i][j].color = color;
                    }
                }
            }
                
        }
    }

    else
    {
        for (i = 0; i < dimensions.picture_height; i++)
        {
            for (j = 0; j < dimensions.picture_width; j++)
            {
                if (is_bg_snowflake(picture, dimensions, i, j))
                {
                    color = pick_color(snowflake_colors, 4);
                    picture[i][j].symbol = '*';
                    picture[i][j].color = color;
                }
            }
        }
    }
}


int is_bg_snowflake(Cell **picture, Dimensions dimensions, int row, int column)
{
    if ((row > dimensions.picture_height - 1) || (column > dimensions.picture_width - 1))
    {
        printf("Index error (is_snowflake)");
        exit(1);
    } 

    if (check_neighbours(picture, dimensions, '*', row, column))
    {
        return 0;
    }

    /* check if cell has a space and is not in the middle of ascii art */
    if (picture[row][column].symbol == ' ' &&
        strcmp(picture[row][column].color, WHITE) == 0)
    { 
        if (is_lucky(7))
        {
            return 1;
        }
    }
    return 0;
}

void clear_snowflakes(Cell **picture, Dimensions dimensions)
{
    int i, j;

    for (i = 0; i < dimensions.picture_height; i++)
    {
        for (j = 0; j < dimensions.picture_width; j++)
        {
            if (picture[i][j].symbol == '*' &&
                strcmp(picture[i][j].color, BRIGHT_YELLOW) != 0)
            {
                picture[i][j].symbol = ' ';
            }
        }
    }
}

void acid_snow(Cell **picture, Dimensions dimensions)
{
    while(1)
    {
        printf("\033[H\033[J");
        add_snowflakes(picture, dimensions, 1);
        print_tree(picture, dimensions);
        usleep(300000);
        clear_snowflakes(picture, dimensions);
    }
}

void make_it_snow(Cell **picture, Cell **copy, Dimensions dimensions, int in_foreground)
{
    while(1)
    {
        printf("\033[H\033[J");
        add_snowflakes(copy, dimensions, in_foreground);
        print_tree(copy, dimensions);
        restore_copy(picture, copy, dimensions);
        usleep(300000);
    }
}




