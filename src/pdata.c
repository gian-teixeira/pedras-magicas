#include <pdata.h>

// Alloc the text and pattern based on the 
// size arguments
void process_data_init(process_data_t *pdata, int text_size, int pattern_size)
{
    pdata->text = malloc(text_size);
    pdata->pattern = malloc(pattern_size);
}

// Clear the memory allocated to text and pattern
void process_data_clear(process_data_t *pdata)
{
    free(pdata->text);
    free(pdata->pattern);
}
