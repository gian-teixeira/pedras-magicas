#include <pdata.h>

void process_data_init(process_data_t *pdata, int text_size, int pattern_size)
{
    pdata->text = malloc(text_size);
    pdata->pattern = malloc(pattern_size);
}

void process_data_clear(process_data_t *pdata)
{
    free(pdata->text);
    free(pdata->pattern);
}


void read_data(process_data_t *data,int gem_count,FILE *input_file){
    
    int buffer_size = MAX_TEXT_SIZE + MAX_PATTERN_SIZE;
    char *buffer = malloc(buffer_size);
    
    for(int i = 0; i < gem_count; i++) {
        fgets(buffer, buffer_size, input_file);
        process_data_init(&(data[i]), MAX_TEXT_SIZE, MAX_PATTERN_SIZE);
        strcpy(data[i].pattern, strtok(buffer," \n"));
        strcpy(data[i].text, strtok(NULL," \n"));
    }
    free(buffer);
    
}

void search_function(int *ans,int (*match_function)(),process_data_t *data,int gem_count){
    int aux1,aux2;
    for(int i=0;i<gem_count;i++){
        aux1 = match_function(data[i].text,data[i].pattern,0);
        aux2 = match_function(data[i].text,data[i].pattern,1);
        ans[i] = (min(aux1,aux2)) + 1;
    }
    
}

void erase_data(process_data_t *data, int gem_count){
    for(int i = 0; i < gem_count; i++) {
        process_data_clear(&(data[i]));
    }
}