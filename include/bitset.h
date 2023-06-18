#ifndef BITSET_H
#define BITSET_H

#include <stdlib.h>
#include <string.h>

typedef struct bitset bitset_t;

struct bitset {
    char *block;
    int block_count;
    int size;
};

bitset_t *bitset_create(int size);
void bitset_destroy(bitset_t *set);
void bitset_set(bitset_t *set, int pos, int value);
int bitset_get(bitset_t *set, int pos);
void bitset_and(bitset_t *target, bitset_t *other);
void bitset_or(bitset_t *target, bitset_t *other);
void bitset_sll(bitset_t *set);
void bitset_srl(bitset_t *set);

#endif