#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <util.h>
#include <pqueue.h>
#include <thcontrol.h>
#include <strmatch/bruteforce.h>
#include <strmatch/shiftand.h>
#include <strmatch/bmh.h>

#define THREAD_NUMBER       16
#define MAX_GEM_SIZE        10001
#define MAX_PATTERN_SIZE    101

int main(int argc, char *argv[]){
    uint chosen_method, gem_count;
    FILE *input_file, *output_file;

    int (*method[3])() = { 
        bruteforce, bmh, shiftAND 
    };

    chosen_method = atoi(argv[2]) - 1;
    if(chosen_method < 0 || chosen_method > 2) error("<method>", 22);
    input_file = fopen(argv[1],"r");
    output_file = change_extension(argv[1]);

    fscanf(input_file, "%d ", &gem_count);
    process_queue_t *match_queue = process_queue_create(gem_count);
    process_queue_read(match_queue, MAX_GEM_SIZE, MAX_PATTERN_SIZE, input_file);
    int *ans;

    pthread_t controller;
    controller_arg_t arg = { method[chosen_method], THREAD_NUMBER, match_queue };
    pthread_create(&controller, NULL, thread_controller, (void*)&arg);
    pthread_join(controller, (void**)&ans);
    write_answers(ans,gem_count,output_file);

    free(ans);
    process_queue_destroy(match_queue);
    fclose(input_file);
    fclose(output_file);
	return 0;
}
