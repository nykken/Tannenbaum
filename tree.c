#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "tree_utility.h"
#include "constants.h"
#include "fluff.h"
#include "snow.h"
#include "arg_parser.h"
#include "error_handling.h"

int main(int argc, char* argv[])
{

    int tree_height;
    int i, j;
    Dimensions dimensions;
    Cell **picture;
    Cell **copy;
    Arguments arguments;

    srand(time(NULL));   

    arguments = parse_arg(argc, argv);
    if (arguments.tree_height)
    {
        tree_height = arguments.tree_height;
    }
    else
    {
        tree_height = determine_tree_height(MIN_HEIGHT, MAX_HEIGHT);
    }

    dimensions = get_dimensions(tree_height);
    picture = malloc_picture(dimensions);
    prepare_picture(picture, dimensions);
    copy = copy_array(picture, dimensions);
    if (copy == NULL)
    {
        free(picture);
        malloc_error();
    }
    
    if (arguments.snow_mode == 'a')
    {
        acid_snow(picture, dimensions);
    }
    else if (arguments.snow_mode == 'f')
    {
        make_it_snow(picture, copy, dimensions, 1);   
    }
    else if (arguments.snow_mode == 'b')
    {
        make_it_snow(picture, copy, dimensions, 0);    
    }
    else if (arguments.snow_mode == 'n')
    {
        print_tree(picture, dimensions);   
    }

    free_picture(picture, dimensions);
    free_picture(copy, dimensions);
}
