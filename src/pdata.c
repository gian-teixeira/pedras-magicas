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
