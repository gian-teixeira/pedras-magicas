#include <strmatch/shiftand.h>
#include <stdio.h>

/* The cycle is relevant just while all letters of pattern have
 * not yet traversed the whole text */

/*int shiftAND(char *text, char *pattern, int rev){   
	int text_size = strlen(text);
  	int pattern_size = strlen(pattern);
	int to_seek = text_size + pattern_size - 1;
    int dir = rev ? -1 : 1;

    bitset_t *state = bitset_create(pattern_size);
    bitset_t *mask[26];

    /* Creating the bitset for each lowercase letter 
    for(int i = 0; i < 26; i++) {
        mask[i] = bitset_create(pattern_size);
    }
  
	/* Setting the mask for each pattern's letter 
	for(int i = 0; i < pattern_size; i++) {
        bitset_set(mask[pattern[i] - 'a'], i, 1);
    }

    int ans = NO_MATCH;
	/* Testing the match until the cycle cannot change the result 
	for(int i = 0; i < to_seek; i++){
        int offset = text_size + i*dir - rev;
		int pos = getpos(text_size, offset);
        bitset_sll(state);
        bitset_set(state, 0, 1);
        bitset_and(state, mask[text[pos] - 'a']);
   		if(bitset_get(state, pattern_size - 1)) {
            int start_offset = pos - pattern_size*dir + dir;
            ans = getpos(text_size, start_offset);
            break;
        }
	}

    bitset_destroy(state);
    for(int i = 0; i < 26; i++) {
        bitset_destroy(mask[i]);
    }
    
	return ans;
}*/

int shiftAND(char *text, char *pattern, int rev){   
	int text_size = strlen(text);
  	int pattern_size = strlen(pattern);
	int to_seek = text_size + pattern_size - 1;
    int dir = rev ? -1 : 1;

    /* Out of declarations, the casting of interger constants to 
     * __int128 is needed to prevent errors. So, since the number 1 
     * is used to bit operations, is created a constant to it */
    const __int128 _1 = 1;
	__int128 match = _1 << (pattern_size-1);
	__int128 state = 0;
  	__int128 mask[26];
  
  	memset(&mask, 0, sizeof mask);
	for(int i = 0; i < pattern_size; i++)
		mask[pattern[i] - 'a'] |= _1 << i;
	
	for(int i = 0; i < to_seek; i++){
        int offset = text_size + i*dir - rev;
		int pos = getpos(text_size, offset);
    	state = ((state << 1) | _1) & mask[text[pos] - 'a'];
   		if(state >= match) {
            int start_offset = pos - pattern_size*dir + dir;
            return getpos(text_size, start_offset);
        }
	}
    
	return NO_MATCH;
}
