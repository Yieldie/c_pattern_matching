#include <stdlib.h>

#ifndef HASHMAP_H
#define HASHMAP_H

struct hash_entry {
	unsigned int c; //input char
	int q; //destination state in DFA
	struct hash_entry *next; //chaining method of collision resolving
};

/**
 * Returns value of some hash function for the unsigned int c (representing the UTF-8 char).
 */
int hash(unsigned int c);

/**
 * Adds new entry to the hash table.
 */
void add_state(struct hash_entry *hmap[], int m, unsigned int c, int q);

/**
 * Finds an entry for char c in the hash table.
 */
struct hash_entry *find(struct hash_entry *hmap[], int m, unsigned int c);

/**
 * Gets the transition from current state on input char c.
 */
int get_state(struct hash_entry *hmap[], int m, unsigned int c);

#endif

