#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "tree_utility.h"
#include "constants.h"
#include "fluff.h"

const char STARS[] = {'*', '@', '&', 'o', '+', '$', 's'};
const char ORNAMENTS[] = {'%', 'O', '#'};
const char *ORNAMENT_COLORS[] = {BRIGHT_RED, BRIGHT_MAGENTA, BRIGHT_CYAN};

int determine_tree_height(int min, int max)
{
    int tree_height;
    tree_height = (rand() % (max - min + 1)) + min;
    return tree_height;                                                           
}

int is_lucky(int chance)
{
    int lucky_number;
    lucky_number = rand() % chance;
    if (lucky_number == 0)
    {
        return 1;
    }
    return 0;
}

char pick_star(void)
{   
    int index;
    char star;

    index = rand() % 7;
    star = STARS[index];
    return star;
}

Dimensions get_dimensions(int tree_height)
{
    Dimensions dimensions;
    dimensions.picture_height = get_picture_height(tree_height);
    dimensions.picture_width = get_picture_width(tree_height);
    dimensions.tree_height = tree_height;
    dimensions.star_height = get_star_height(tree_height);
    dimensions.trunk_height = get_trunk_height(tree_height);
    dimensions.trunk_width = get_trunk_width(tree_height);
    dimensions.middle_column = dimensions.picture_width / 2;

    return dimensions;
}

Cell **malloc_picture(Dimensions dimensions)
{
    int i, k, height, width;
    Cell **picture;

    height = dimensions.picture_height;
    width = dimensions.picture_width;

    picture = malloc(height * sizeof(Cell *));
    if (picture == NULL) 
    {
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }

    for (i = 0; i < height; i++) 
    {
        picture[i] = malloc(width * sizeof(Cell));
        if (picture[i] == NULL) 
        {
            for (k = 0; k < i; k++) {
                free(picture[k]); 
            }
            free(picture); 
            fprintf(stderr, "Memory allocation failed");
            exit(1);
        }
    }

    return picture;
}

void init_picture(Cell **picture, Dimensions dimensions)
{
    int i, j, height, width;
    Cell cell;

    height = dimensions.picture_height;
    width = dimensions.picture_width;
    cell.symbol = ' ';
    cell.color = WHITE;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            picture[i][j] = cell;
        }
    }
}

void free_picture(Cell **picture, Dimensions dimensions)
{
    int i, height;
    height = dimensions.picture_height;

    for (i = 0; i < height; i++) 
    {
        free(picture[i]);
    }

    free(picture);
}

int get_trunk_width(int tree_height)
{
    if (tree_height >= 3 && tree_height <= 4)
    {
        return 1;        
    }
    else if (tree_height >= 5 && tree_height <= 11)
    {
        return 3;
    }
    else if (tree_height >= 12 && tree_height <= 17)
    {
        return 5;
    }
    /* if invalid tree size */
    printf("Error: Invalid tree size %d\n (get_trunk_width)", tree_height);
    exit(1);
}

int get_trunk_height(int tree_height)
{
    if (tree_height >= 3 && tree_height <= 4)
    {
        return 1;
    }
    else if (tree_height >= 5 && tree_height <= 11)
    {
        return 2;
    }
    else if (tree_height >= 12 && tree_height <= 14)
    {
        return 3;
    }
    else if (tree_height >= 15 && tree_height <= 17)
    {
        return 4;
    }
    /* if invalid tree size */
    printf("Error: Invalid tree size %d\n (get_trunk_height)", tree_height);
    exit(1);
}

int get_star_height(int tree_height)
{
    if (tree_height >= 3 && tree_height <= 8)
    {
        return 1;
    }
    else if (tree_height >= 9 && tree_height <= 17)
    {
        return 3;
    }
    /* if invalid tree size */
    printf("Error: Invalid tree size %d\n (get_star_height)", tree_height);
    exit(1);
}

int get_picture_height(int tree_height)
{   
    int trunk_height, star_height;
    trunk_height = get_trunk_height(tree_height);
    star_height = get_star_height(tree_height);
    return tree_height + trunk_height + star_height;
}

int get_picture_width(int tree_height)
{
    return (tree_height * 2) + 1;
}

int check_neighbours(Cell **picture, Dimensions dimensions, char symbol, int row, int column)
{
    if (row > 0)
    {
        if (picture[row - 1][column].symbol == symbol)
        {
            return 1;
        }
    }
    if (row < dimensions.picture_height - 1)
    {
        if (picture[row + 1][column].symbol == symbol)
        {
            return 1;
        }
    }
    if (column > 0)
    {
        if (picture[row][column -1].symbol == symbol)
        {
            return 1;
        }
    }
    if (column < dimensions.picture_width - 1)
    {
        if (picture[row][column + 1].symbol == symbol)
        {
            return 1;
        }
    }
    return 0;
}

int is_ornament(Cell **picture, Dimensions dimensions, int row, int column)
{
    int i, lucky_number;

    for (i = 0; i < 3; i++)
    {
        if (check_neighbours(picture, dimensions, ORNAMENTS[i], row, column))
        {
            return 0;
        }
    }
    lucky_number = rand() % 3;
        if (lucky_number)
        {
            return 1;
        }

    return 0;
}

char pick_ornament(void)
{
    int index;
    char ornament;
    
    index = rand() % 3;
    ornament = ORNAMENTS[index];
    return ornament;
}

const char *pick_color(const char **colors, int size) 
{
    int index;
    index = rand() % size; 
    return colors[index]; 
}

const char *pick_ornament_color(void)
{
    return pick_color(ORNAMENT_COLORS, 3);
}

void add_star(Cell **picture, Dimensions dimensions)
{
    int star_column;
    char star;

    star_column = dimensions.middle_column;
    star = pick_star();

    if (dimensions.star_height == 1)
    {
        picture[0][star_column].symbol = star;
        picture[0][star_column].color = BRIGHT_YELLOW;
        return;
    }
    else if (dimensions.star_height == 3)
    {
        /* boundary check */
        if (star_column - 3 < 0 ||
        star_column + 3 >= dimensions.picture_width - 1)
        {
            printf("Index error (add_star)");
            exit(1);
        }
        picture[0][star_column - 2].symbol = '\\';
        picture[0][star_column - 2].color = BRIGHT_YELLOW;
        picture[0][star_column + 2].symbol = '/';
        picture[0][star_column + 2].color = BRIGHT_YELLOW;
        picture[1][star_column - 3].symbol = '-';
        picture[1][star_column - 3].color = BRIGHT_YELLOW;
        picture[1][star_column + 3].symbol = '-';
        picture[1][star_column + 3].color = BRIGHT_YELLOW;
        picture[1][star_column].symbol = star;
        picture[1][star_column].color = BRIGHT_YELLOW;
        picture[2][star_column - 2].symbol = '/';
        picture[2][star_column - 2].color = BRIGHT_YELLOW;
        picture[2][star_column + 2].symbol = '\\';
        picture[2][star_column + 2].color = BRIGHT_YELLOW;
        return;
    }
    else
    /* invalid star height */
    {  
        printf("Invalid star height");
        exit(1);
    }
}

void add_foliage(Cell **picture, Dimensions dimensions)
{
    int start_row, end_row, width, middle_column, counter;
    int i, j, left_edge, right_edge;
    char ornament;
    const char *color;

    start_row = dimensions.star_height;  
    end_row = start_row + dimensions.tree_height - 1;
    width = dimensions.picture_width;
    middle_column = dimensions.middle_column;
    counter = 1;

    for (i = start_row; i <= end_row; i++)
    {
        for (j = 0; j < width; j ++)
        {
            left_edge = middle_column - counter;
            right_edge = middle_column + counter;
            if (j == left_edge)
            {
                picture[i][j].symbol = '/';
                picture[i][j].color = BRIGHT_GREEN;
            }
            else if (j == right_edge)
            {
                picture[i][j].symbol = '\\';
                picture[i][j].color = BRIGHT_GREEN;
            }
            else if (j > left_edge && j < right_edge)
            {
                if (is_ornament(picture, dimensions, i, j))
                {
                    ornament = pick_ornament();
                    color = pick_ornament_color();
                    picture[i][j].symbol = ornament;
                    picture[i][j].color = color;
                }
                else
                {
                    picture[i][j].symbol = 'V';
                    picture[i][j].color = GREEN;
                }
            }
        }
        counter++;
    }
}

void add_trunk(Cell **picture, Dimensions dimensions)
{
    int i, j;
    int start_column, start_row, trunk_width, trunk_height;
    trunk_width = dimensions.trunk_width;
    trunk_height = dimensions.trunk_height;

    start_row = dimensions.picture_height - trunk_height;
    start_column = dimensions.middle_column - (trunk_width / 2);

    for (i = 0; i < trunk_height; i ++)
    {
        for (j = 0; j < trunk_width; j++)
        {
            picture[start_row + i][start_column + j].symbol = '|';
            picture[start_row + i][start_column + j].color = RED;
        }
    }    
}

void add_foliage_bottom(Cell **picture, Dimensions dimensions)
{
    int i, j;
    
    i = dimensions.picture_height - dimensions.trunk_height;

    for(j = 0; j < dimensions.picture_width; j++)
    {
        if (picture[i][j].symbol == ' ')
        {
            picture[i][j].symbol = '"';
            picture[i][j].color = BRIGHT_GREEN;
        }
        
    }
}

void add_ground(Cell **picture, Dimensions dimensions)
{
    int row, column;
    row = dimensions.picture_height - 1;


    for (column = 0; column < dimensions.picture_width; column++)
    {
        picture[row][column].symbol = '_';
        picture[row][column].color = BRIGHT_WHITE;  
    }
}

void prepare_picture(Cell **picture, Dimensions dimensions)
{
    init_picture(picture, dimensions);
    add_star(picture, dimensions);
    add_foliage(picture, dimensions);
    add_ground(picture, dimensions);
    add_trunk(picture, dimensions);
    add_foliage_bottom(picture, dimensions);
    add_fluff(picture, dimensions);
}

void print_tree(Cell **picture, Dimensions dimensions)
{
    int i, j;

    for (i = 0; i < dimensions.picture_height; i++)
    {
        for (j = 0; j < dimensions.picture_width; j++)
        {
            printf("%s", picture[i][j].color);
            printf("%c", picture[i][j].symbol);
            printf("%s", COLOR_END);
        }
        printf("\n");
    }
}

Cell **copy_array(Cell **picture, Dimensions dimensions)
{
    int i, j, k, height, width;
    Cell **copy;

    height = dimensions.picture_height;
    width = dimensions.picture_width;

    copy = malloc(height * sizeof(Cell *));
    if (copy == NULL) 
    {
        return NULL;
    }

    for (i = 0; i < height; i++) 
    {
        copy[i] = malloc(width * sizeof(Cell));
        if (copy[i] == NULL) 
        {
            for (k = 0; k < i; k++) {
                free(copy[k]);
            }
            free(copy);
            return NULL;
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            copy[i][j] = picture[i][j];
        }
    }
    return copy;
}

void restore_copy(Cell **picture, Cell **copy, Dimensions dimensions)
{
    int i, j;

    for (i = 0; i < dimensions.picture_height; i++)
    {
        for (j = 0; j < dimensions.picture_width; j++)
        {
            copy[i][j].symbol = picture[i][j].symbol;
            copy[i][j].color = picture[i][j].color;
        }
    }
}

