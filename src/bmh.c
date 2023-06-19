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
    for(int i = 0; i < pattern_size - 1; i++){
        int pos = i-(rev*(pattern_size-1));
        pos = abs(pos);
        shift_table[pattern[pos] - 'a'] = pattern_size - i - 1;
    }

    int i, j, k;
    int initial_text_pos;
    int cur_text_pos, cur_pat_pos;
    int offset;

    i = 0;
    while(i < to_seek) {
        offset = text_size + i;
        offset += (pattern_size - 1);
        
        j = pattern_size;
        k = offset;
        initial_text_pos = getpos(text_size, k);
        
        while (j > 0) {
            cur_text_pos = getpos(text_size, k);
            cur_pat_pos = rev*pattern_size-j+1-rev;
            cur_pat_pos = (abs(cur_pat_pos));
            if(text[cur_text_pos] != pattern[cur_pat_pos]) break;
            k--;
            j--;
        }

        if(j == 0) {
            printf("%d ",k);
            offset = k + (pattern_size*rev) -rev+1;
            printf("WHAT:%d\n",getpos(text_size, offset));
            return getpos(text_size, offset);
        }

        i = shift_table[text[initial_text_pos] - 'a'] + i;
    }

    return NO_MATCH;
}