#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <config.h>
#include <util.h>
#include <pqueue.h>
#include <thcontrol.h>
#include <strmatch/bruteforce.h>
#include <strmatch/shiftand.h>
#include <strmatch/bmh.h>

int main(int argc, char *argv[]){
    int chosen_method, gem_count, *ans;
    FILE *input_file, *output_file;
    int (*method[3])() = { 
        bruteforce, bmh, shiftAND 
    };
    
    // Processing the main arguments
    chosen_method = atoi(argv[2]) - 1;
    if(chosen_method < 0 || chosen_method > 2) error("<method>", 22);
    input_file = fopen(argv[1],"r");
    output_file = take_output(argv[1]);

    // Geting the data and creating the process queue
    gem_count = get_int(input_file);
    process_queue_t *match_queue = process_queue_create(gem_count);
    process_queue_read(match_queue, MAX_GEM_SIZE, MAX_PATTERN_SIZE, input_file);
 
    // Calling the controller 
    pthread_t controller;
    controller_arg_t arg = {method[chosen_method], THREAD_NUMBER, match_queue};
    pthread_create(&controller, NULL, thread_controller, (void*)&arg);

    //Joining the threads and printing the answers
    pthread_join(controller, (void**)&ans);
    write_answers(ans, gem_count, output_file);

    // Deallocating memory
    process_queue_destroy(match_queue);
    fclose(input_file);
    fclose(output_file);
    free(ans);

	return 0;
}
