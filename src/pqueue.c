#include <pqueue.h>

process_queue_t *process_queue_create(int size)
{
	process_queue_t *new_queue = malloc(sizeof(process_queue_t));
	new_queue->item = malloc((size+1)*sizeof(process_data_t));
	new_queue->end = new_queue->item + size;
	new_queue->first = new_queue->item;
	new_queue->last = new_queue->item;
	new_queue->next_item_id = 0;
	new_queue->size = size;

	return new_queue;
}

void process_queue_destroy(process_queue_t *pqueue)
{
    while(pqueue->first != pqueue->end){
        process_data_clear(pqueue->first);
        pqueue->first++;
    }
    free(pqueue->item);
	free(pqueue);
}

void process_queue_push(process_queue_t *pqueue, process_data_t pdata)
{
	pdata.id = pqueue->next_item_id;
	*(pqueue->last) = pdata;
	pqueue->next_item_id++;
	pqueue->last++;
}

process_data_t process_queue_pop(process_queue_t *pqueue)
{
	process_data_t poped_data;
	poped_data = *(pqueue->first);
	pqueue->first++;

	return poped_data;
}

bool process_queue_is_empty(process_queue_t *pqueue)
{
	return pqueue->first == pqueue->end;
}

void process_queue_read(process_queue_t *pqueue, 
    int max_text_size, int max_pattern_size, FILE *input_file)
{    
    size_t buffer_size = max_text_size + max_pattern_size;
    char *buffer = malloc(buffer_size);
    process_data_t aux_data;

    for(int i = 0; i < pqueue->size; i++) {
        fgets(buffer, buffer_size, input_file);
       	
        process_data_init(&aux_data, max_text_size, max_pattern_size);
        strcpy(aux_data.pattern, strtok(buffer," \n"));
        strcpy(aux_data.text, strtok(NULL," \n"));
        process_queue_push(pqueue, aux_data);
    }
    
    free(buffer);
}
