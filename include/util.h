#ifndef UTIL
#define UTIL

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define min(a,b) a < b ? a : b

char* parse_name(char *name);
FILE* take_output(FILE* input);
void write_answers(int* ans, int gems, FILE* out);

#endif
