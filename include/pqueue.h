#ifndef PQUEUE
#define PQUEUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <pdata.h>

typedef struct process_queue process_queue_t;

struct process_queue {
    process_data_t *item;
    process_data_t *first;
	process_data_t *last;
	process_data_t *end;
    int next_item_id;
    int size;
};

process_queue_t *process_queue_create(int size);
void process_queue_destroy(process_queue_t *pqueue);
void process_queue_push(process_queue_t *pqueue, process_data_t pdata);
process_data_t process_queue_pop(process_queue_t *pqueue);
bool process_queue_is_empty(process_queue_t *pqueue);

#endif
