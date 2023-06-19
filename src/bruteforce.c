#include <strmatch/bruteforce.h>

int bruteforce(char* tex, char* pat, int rev){   
    int text_size = strlen(tex);
    int pattern_size = strlen(pat);
    int to_seek = text_size + pattern_size - 1;
    int dir = rev ? -1 : 1;

    
    int n = strlen(tex);
    int m = strlen(pat);

    int p0 = 0;
    if(rev) {
        strrev(pat);
        p0 = n - m + 1;
    }

    for(int i = 0; i < m + n - 1; i++) {
        int begin = (p0 + i) % n;

        int t = begin;
        int p = 0;
        int match = 1;

        while(p < m) {
            if(pat[p] != tex[t]) {
                match = 0;
                break;
            }
            t = (t+1) % n;
            p++;
        }
        
        if(!match) continue;
        if(rev) return t - 1;
        else return begin;
    }


    /*for(int i=0;i<to_seek;i++) 
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
    }*/
    
    return NO_MATCH;
}
