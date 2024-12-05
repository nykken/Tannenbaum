#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arg_parser.h"
#include "error_handling.h"

void print_usage(const char *prog_name) 
{
    fprintf(stderr, "Usage: %s [-t tree_height] [-s snow_mode]\n", prog_name);
    fprintf(stderr, "  -t tree_height   : Tree height (optional, between 3 and 17)\n");
    fprintf(stderr, "  -s snow_mode     : Snow mode (optional, 'a' (acid), 'f' (in foreground), 'b' (in background) or 'n' (none))\n");
}

Arguments parse_arg(int argc, char *argv[])
{
    int i;
    int tree_height;
    char snow_mode;
    Arguments arguments = {0, 'f'};

    if (argc == 1)
    {
        return arguments;
    }
    else
    {
        for (i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "-t") == 0)
            {
                if (i + 1 < argc)
                {
                    tree_height = atoi(argv[i+1]);
                    if (tree_height >= 3 && tree_height <= 17)
                    {
                        arguments.tree_height = tree_height;
                    }
                    else
                    {
                        arg_error(argv[0], "tree_height must be between 3 and 17.");
                    }
                    i++;
                }
                else
                {
                    arg_error(argv[0], "missing value for -t tree_height.");
                }
            }
            else if (strcmp(argv[i], "-s") == 0)
            {
                if (i + 1 < argc)
                {
                    /* take the first character */
                    snow_mode = argv[i+1][0];
                    if (snow_mode == 'a' || snow_mode == 'f' || snow_mode == 'b' || snow_mode == 'n')
                    {
                        arguments.snow_mode = snow_mode;
                    }
                    else
                    {
                        arg_error(argv[0], "snow_mode must be 'a', 'f', 'b', or 'n'.");
                    }
                    i++;
                }
                else
                {
                    arg_error(argv[0], "missing value for -s snow_mode.");
                }
            }
            else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
            {
                print_usage(argv[0]);
                exit(0);
            }
            else
            {
                arg_error(argv[0], "unknown argument.");
            }
        }
    }
    return arguments;
}
