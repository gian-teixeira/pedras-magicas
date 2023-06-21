#include <thcontrol.h>

// Takes data from a data queue and uses the required
// string match function to process it, saving the
// result in the related arg answer address
void *first_ocurrence_finder(void *arg_v)
{
    finder_arg_t *arg = (finder_arg_t*)arg_v;
    
    int (*match)() = arg->match_function;
    process_data_t match_data;
    uint target_index;
    int stop = 0;
    
    while(1) {
        pthread_mutex_lock(arg->data_lock);
        if(!process_queue_is_empty(arg->match_queue)) {
            match_data = process_queue_pop(arg->match_queue);
        }
        else stop = 1;
        pthread_mutex_unlock(arg->data_lock);
        
        if(stop) break;

        int direct_ans = (*match)(match_data.text, match_data.pattern, 0) + 1;
        int reverse_ans = (*match)(match_data.text, match_data.pattern, 1) + 1;
        arg->ans[match_data.id] = min(direct_ans, reverse_ans);
        process_data_clear(&match_data);
    }

    return NULL;
}

// Controll the exection if a certain number of occurence
// finders
void *thread_controller(void *argv)
{
    controller_arg_t *arg = (controller_arg_t*)argv;

    pthread_t *thread;
    pthread_mutex_t data_lock;
    finder_arg_t finder_arg;
    int *ans;
    
    ans = malloc(arg->match_queue->size * sizeof(int));
    thread = malloc(arg->thread_number * sizeof(pthread_t));
    pthread_mutex_init(&data_lock, NULL);
    finder_arg = (finder_arg_t){
        .data_lock = &data_lock,
        .match_queue = arg->match_queue,
        .match_function = arg->match_function,
        .ans = ans
    };
    
    // Start finders execution
    for(int i = 0; i < arg->thread_number; i++)
        pthread_create(&thread[i], NULL, 
            first_ocurrence_finder, (void*)&finder_arg);
    
    // Stop finders
    for(int i = 0; i < arg->thread_number; i++)
        pthread_join(thread[i], NULL);

    pthread_mutex_destroy(&data_lock);
    free(thread);
    
    return (void*)ans;
}
