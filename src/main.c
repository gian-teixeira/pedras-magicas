#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <util.h>
#include <pdata.h>
#include <strmatch/bruteforce.h>
#include <strmatch/shiftand.h>
#include <strmatch/bmh.h>

#define MAX_GEM_SIZE        10001
#define MAX_PATTERN_SIZE    101

int main(int argc, char *argv[]){
    int chosen_method, gem_count;
    FILE *input_file, *output_file;

    int (*method[3])() = { 
        bruteforce, bmh, shiftAND 
    };

    chosen_method = atoi(argv[2]) - 1;
    if(chosen_method < 0 || chosen_method > 2) error("<method>", 22);
    input_file = fopen(argv[1],"r");
    output_file = change_extension(argv[1]);

    fscanf(input_file, "%d ", &gem_count);
    process_data_t *data_vector = (process_data_t*) malloc(sizeof(process_data_t)*gem_count);
    read_data(data_vector, gem_count,input_file);
    int *ans= malloc(sizeof(int)*gem_count);
    
    search_function(ans,method[chosen_method],data_vector, gem_count);
    write_answers(ans,gem_count,output_file);

    erase_data(data_vector,gem_count);
    free(ans);
    fclose(input_file);
    fclose(output_file);
    
	return 0;
}
