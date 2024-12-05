#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H
#include <stdio.h>
#include <stdlib.h>

void malloc_error(void);
void size_error(char *message);
void arg_error(const char *prog_name, char *message);
void index_error(char *message);

#endif
