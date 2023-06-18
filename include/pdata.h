#ifndef PDATA
#define PDATA

#define MAX_TEXT_SIZE      10002
#define MAX_PATTERN_SIZE     102

typedef struct process_data process_data_t;

struct process_data {
    char *text;
    char *pattern;
    int id;
};

void process_data_init(process_data_t *pdata, int text_size, int pattern_size);
void process_data_clear(process_data_t *pdata);

#endif