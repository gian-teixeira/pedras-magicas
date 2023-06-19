#include <strmatch/shiftand.h>
#include <stdio.h>

int shiftAND(char *text, char *pattern, int rev){   
	int text_size = strlen(text);
  	int pattern_size = strlen(pattern);
    int dir = rev ? -1 : 1;
    
    if(rev) strrev(pattern);

    // Out of declarations, the casting of interger constants to 
    // __int128 is needed to prevent errors. So, since the number 1 
    // is used to bit operations, is created a constant to it */
    const __int128 _1 = 1;
	__int128 match = _1 << (pattern_size-1);
	__int128 state = 0;
  	__int128 mask[26];
    
    // Creating the masks according pattern's letter 
    memset(&mask, 0, sizeof(mask));
    for(int i = 0; i < pattern_size; i++) {
        mask[pattern[i] - 'a'] |= _1 << i;
    }
    /*int pos;
  	memset(&mask, 0, sizeof mask);
	for(int i = 0; i < pattern_size; i++){
        if(rev) pos = pattern_size - 1 - i;
        else pos = i;
		mask[pattern[pos] - 'a'] |= _1 << i;
    }*/
    
    // Matching

    int initial_pos;
    int current_pos;
    int offset;

    if(rev) initial_pos = text_size - pattern_size + 1;
    else initial_pos = 0;

	for(int i = 0; i < text_size + pattern_size - 1; i++) {
        current_pos = (initial_pos + i) % text_size;
    	state = ((state << 1) | _1) & mask[text[current_pos] - 'a'];
   		if(state >= match) {
            if(!rev) offset = current_pos - pattern_size + 1;
            else offset = current_pos;
            
            return getpos(text_size, offset);
        }
	}

	return NO_MATCH;
}
