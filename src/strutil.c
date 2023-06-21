#include <strmatch/strutil.h>

// Returns the valid position related to size
int getpos(int size, int offset)
{
    if(offset < 0) offset = size - (-offset % size);
	return offset % size;
}

// Reverses a string
void strrev(char *str)
{
    char *d = str;
    char *u = str + strlen(str) - 1;
    char tmp;
    
    while(d < u) {
        tmp = *d;
        *d = *u;
        *u = tmp;
        d++; u--;
    }
}
