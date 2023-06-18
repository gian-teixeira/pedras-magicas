#ifndef UTIL
#define UTIL

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define END INT_MAX
#define NOT_ANSWERED INT_MIN
#define NO_MATCH 200000
#define min(a,b) a < b ? a : b
#define abs(n) n < 0 ? -n : n

int getpos(int size, int offset);
char* parse_name(char *name);
FILE* change_extension(FILE* input);
void write_answers(int* ans, int gems, FILE* out);

#endif
