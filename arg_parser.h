#ifndef ARG_PARSER_H
#define ARG_PARSER_H

typedef struct {
    int tree_height;
    char snow_mode;
} Arguments;

void print_usage(const char *prog_name);
Arguments parse_arg(int argc, char *argv[]);


#endif

