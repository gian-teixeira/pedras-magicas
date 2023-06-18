#include <util.h>

int getpos(int size, int offset){
    if(offset < 0) offset = size - (-offset % size);
	return offset % size;
}

char *parse_name(char *name){
    char *pt = strrchr(name, '.');
    char *dash = strrchr(name, '/');
    
    if(!dash) dash = name - 1;
    if(!pt || pt < dash)
        pt = name + strlen(name);

    char *parsed = malloc(pt - dash);
    for(int i;;i++){
        if(++dash == pt){
            parsed[i] = '\0';
            break;
        }
        parsed[i] = *dash;
    }

    return parsed;
}