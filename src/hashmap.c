#include <hashmap.h>

int hash(unsigned int c)
{
	return c;
}

void add_state(struct hash_entry *hmap[], int m, unsigned int c, int q)
{
	int h = hash(c) % m;
	struct hash_entry *new = (struct hash_entry *)malloc(sizeof(struct hash_entry));
	new->c = c;
	new->q = q;
	new->next = hmap[h];
	hmap[h] = new;
}

struct hash_entry *find(struct hash_entry *hmap[], int m, unsigned int c)
{
	int h = hash(c) % m;
	struct hash_entry *curr = hmap[h];
	while(curr != NULL) {
		if(curr->c == c) return curr;
		curr = curr->next;
	}
	return NULL;
}

int get_state(struct hash_entry *hmap[], int m, unsigned int c) 
{
	int h = hash(c) % m;
	struct hash_entry *curr = hmap[h];
	while(curr != NULL && curr->c != c) curr = curr->next;
	return (curr == NULL) ? 0 : curr->q;
}
