#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_handling.h"
#include "arg_parser.h"

void malloc_error(void)
{
    fprintf(stderr, "Error: Memory allocation failed\n");
    exit(1);
}

void size_error(char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

void arg_error(const char *prog_name, char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    print_usage(prog_name); 
    exit(1);
}

void index_error(char *message)
{
    fprintf(stderr, "Index error: %s\n", message);
    exit(1);
}


