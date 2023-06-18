#ifndef PDATA
#define PDATA

#include <stdio.h>
#include <util.h>

#define MAX_TEXT_SIZE      10002
#define MAX_PATTERN_SIZE     102

typedef struct process_data process_data_t;

struct process_data {
    char *text;
    char *pattern;
};

void process_data_init(process_data_t *pdata, int text_size, int pattern_size);
void process_data_clear(process_data_t *pdata);
void search_function(int *ans,int (*match_function)(),process_data_t *data,int gem_count);
void read_data(process_data_t *data,int gem_count,FILE *input);
void erase_data(process_data_t *data, int gem_count);


#endif