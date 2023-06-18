#include <bitset.h>

bitset_t *bitset_create(int size)
{
    bitset_t *set = malloc(sizeof(bitset_t));
    set->block_count = (size-1)/8 + 1;
    set->block = malloc(set->block_count);
	set->size = size;
    memset(set->block, 0, set->block_count);
    
    return set;
}

void bitset_destroy(bitset_t *set)
{
    free(set->block);
    free(set);
}

void bitset_set(bitset_t *set, int pos, int value)
{
    int target_block = pos / 8;
    int offset = pos % 8;
    if(value == 1) set->block[target_block] |= (1 << offset);
    else set->block[target_block] &= ~(1 << offset);
}

int bitset_get(bitset_t *set, int pos)
{
    int target_block = pos / 8;
    int offset = pos % 8;
    return (set->block[target_block] & (1 << offset)) >> offset;
}

void bitset_and(bitset_t *target, bitset_t *other)
{
	int with;
    for(int i = 0; i < target->block_count; i++){
		if(other->block_count < i) with = 0;
		else with = other->block[i];
        target->block[i] &= with;
	}
}

void bitset_or(bitset_t *target, bitset_t *other)
{
	int with;
    for(int i = 0; i < target->block_count; i++){
		if(other->block_count < i) with = 0;
		else with = other->block[i];
        target->block[i] |= with;
	}
}

void bitset_sll(bitset_t *set)
{
    int carry_out = 0;
    int carry_in = 0;
    for(int i = 0; i < set->block_count; i++) {
        carry_out = (set->block[i] & (1 << 7)) >> 7;
        set->block[i] <<= 1;
        set->block[i] |= carry_in;
        carry_in = carry_out;
    }
}

void bitset_srl(bitset_t *set)
{
    int carry_out = 0;
    int carry_in = 0;
    for(int i = 0; i < set->block_count; i++) {
        carry_out = set->block[i] & 1;
        set->block[i] >>= 1;
        set->block[i] |= carry_in << 7;
        carry_in = carry_out;
    }
}