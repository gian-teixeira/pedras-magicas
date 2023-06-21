#include <strmatch/bruteforce.h>

// Finds the first occurence of pat in tex using the brute
// force approach. Works in forward order if rev is true or 
// in the inverse order otherwise
int bruteforce(char* tex, char* pat, int rev){    
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
            p++;
            if(p < m) t = (t+1) % n;
        }
        
        if(!match) continue;
        if(rev) return t;
        else return begin;
    }
    
    return NO_MATCH;
}
