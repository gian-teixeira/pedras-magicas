#ifndef THCONTROL
#define THCONTROL

#include <stdlib.h>
#include <pthread.h>
#include <util.h>
#include <pdata.h>
#include <pqueue.h>

typedef struct finder_arg finder_arg_t;
typedef struct controller_arg controller_arg_t;

struct finder_arg {
    process_queue_t *match_queue;
    pthread_mutex_t *data_lock;
    int (*match_function)();
    int *ans;
};

struct controller_arg {
    int (*match_function)();
    int thread_number;
    process_queue_t *match_queue;
};

void *first_ocurrence_finder(void *arg_v);
void *thread_controller(void *arg_v);

#endif
