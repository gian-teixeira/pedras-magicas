#include <strmatch/bmh.h>
#include <stdio.h>

// Função que converte char em index !!!

int bmh(char* text, char* pattern, int rev){
    int pattern_size = strlen(pattern);
    int text_size = strlen(text);
    int to_seek = text_size + pattern_size;
    int dir = rev ? -1 : 1;
    
    int shift_table[26];
    for(int i = 0; i < 26; i++) shift_table[i] = pattern_size;    
    for(int i = 0; i < pattern_size - 1; i++)
        shift_table[pattern[i] - 'a'] = pattern_size - i - 1;

    int i, j, k;
    int initial_text_pos;
    int cur_text_pos;
    int offset;
    
    i = 0;
    while(i < to_seek) {
        offset = text_size + i*dir - rev;
        offset += (pattern_size - 1)*dir;
        
        j = pattern_size;
        k = offset;
        initial_text_pos = getpos(text_size, k);
        
        while (j > 0) {
            cur_text_pos = getpos(text_size, k);
            if(text[cur_text_pos] != pattern[j-1]) break;
            k -= dir; 
            j--;
        }
        
        if(j == 0) {
            offset = k + dir;
            return getpos(text_size, offset);
        }
        
        i = shift_table[text[initial_text_pos] - 'a'] + i;
    }

    return NO_MATCH;
}