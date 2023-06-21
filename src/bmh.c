#include <strmatch/bmh.h>
#include <stdio.h>

// Finds the first occurence of pat in tex based on the
// Boyer Moore Hospool algorithm. Works in forward order if 
// rev is true or in the inverse order otherwise
int bmh(char* tex, char* pat, int rev){
    int pat_size = strlen(pat);
    int tex_size = strlen(tex);
    int to_seek = tex_size + pat_size;
     
    if(rev) strrev(pat);
    
    // Creating the shift table
    int shift_table[26];
    for(int i = 0; i < 26; i++) shift_table[i] = pat_size;    
    for(int i = 0; i < pat_size - 1; i++)
        shift_table[pat[i] - 'a'] = pat_size - i - 1;
    
    // Helper variables
    int j, i = 0;
    int init_tex_pos, cur_tex_pos, comp_tex_pos;
    int comp_pat_pos;
    
    // Setting the initial position
    if(rev) init_tex_pos = tex_size - pat_size + 1;
    else init_tex_pos = 0;
    
    // Traversing the text
    while(i < pat_size + tex_size - 1) {
        cur_tex_pos = getpos(tex_size, init_tex_pos + i);
        
        // Trying to match the pattern
        for(j = pat_size; j > 0; j--) {
            comp_tex_pos = getpos(tex_size, cur_tex_pos + j - 1);
            comp_pat_pos = j - 1;
            if(tex[comp_tex_pos] != pat[comp_pat_pos]) break;
        }
        
        // Verifying if the match occurs
        comp_tex_pos = getpos(tex_size, cur_tex_pos + pat_size - 1);
        if(j == 0) {
            if(rev) return comp_tex_pos;
            return cur_tex_pos;
        }
        
        // Jump according the shift table
        i += shift_table[tex[comp_tex_pos] - 'a'];
    } 

    return NO_MATCH;
}
