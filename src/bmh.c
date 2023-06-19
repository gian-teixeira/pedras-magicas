#include <strmatch/bmh.h>
#include <stdio.h>

// Função que converte char em index !!!

int bmh(char* tex, char* pat, int rev){
    int pat_size = strlen(pat);
    int tex_size = strlen(tex);
    int to_seek = tex_size + pat_size;
    int dir = rev ? -1 : 1;
    
<<<<<<< HEAD
    
    if(rev) strrev(pat);
    
    // Creating the masks
    int shift_table[26];
    for(int i = 0; i < 26; i++) shift_table[i] = pat_size;    
    for(int i = 0; i < pat_size - 1; i++)
        shift_table[pat[i] - 'a'] = pat_size - i - 1;
    
    int j, i = 0;
    int init_tex_pos, cur_tex_pos, comp_tex_pos;
    int comp_pat_pos;

    if(rev) init_tex_pos = tex_size - pat_size + 2;
    else init_tex_pos = pat_size;

    while(i < pat_size + tex_size - 1) {
        cur_tex_pos = getpos(tex_size, init_tex_pos + i);

        for(j = pat_size; j > 0; j--) {
            comp_tex_pos = getpos(tex_size, cur_tex_pos + j - 1);
            comp_pat_pos = j - 1;
            if(tex[comp_tex_pos] != pat[comp_pat_pos]) 
                break;
        }
        
        comp_tex_pos = getpos(tex_size, cur_tex_pos + pat_size - 1);
        if(j == 0) {
            if(rev) return comp_tex_pos;
            return cur_tex_pos;
        }

        i += shift_table[tex[comp_tex_pos] - 'a'];
=======
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
>>>>>>> 2502f434704d8bcf2f6466c531b20625e4693217
    }

    return NO_MATCH;
}
