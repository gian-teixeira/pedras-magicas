#include <strmatch/bruteforce.h>
#include <stdio.h>

int bruteforce(char* tex, char* pat, int rev){   
    int text_size = strlen(tex);
    int pattern_size = strlen(pat);
    int to_seek = text_size + pattern_size - 1;
    int dir = rev ? -1 : 1;
    
    /*for(int i=0;i<to_seek;i++) 
    {
        int text_initial_offset = text_size + i*dir - rev;
        int text_initial_pos = getpos(text_size, text_initial_offset);
        
		int j = 0;
        for(; j < pattern_size; j++) {
            int text_curr_offset = text_initial_pos + j*dir - rev;
            int text_curr_pos = getpos(text_size, text_curr_offset);
            if(tex[text_curr_pos] != pat[j]) break;
        }
        
		if(j == pattern_size)
        	return text_initial_pos;
    }*/
    
    for(int i=0;i<to_seek;i++) 
    {
        for(int j = 0; j < pattern_size; j++) {
            int offset = i + j*dir - rev;
            int text_pos = getpos(text_size, offset);
            if(tex[text_pos]!=pat[j]) break;
            if(j + 1 == pattern_size) {
                int start_offset = text_pos - pattern_size*dir + dir;
                return getpos(text_size, start_offset);
            }
        }
    }
    
    return NO_MATCH;
}
