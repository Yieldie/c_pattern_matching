#include <stdio.h>
#include <fcntl.h>
#include <hashmap.h>
#include <utf.h>

#define MAX_LEN 100
#define SIZE    100

int main(int argc, char **argv)
{
	// INITIALIZATION

	int fd = 1, m, k, succ;
	unsigned int pat[MAX_LEN], u;
	if(argc > 1) {
		fd = open(argv[1], O_RDONLY);
	}
	m = 0;
    	while((u = get_utf(1)) != (unsigned int)'\n' && u != (unsigned int)'\0' && m < MAX_LEN - 1) {
        	pat[m] = u;
        	m++;
    	}

	struct hash_entry *delta[m + 1][SIZE]; //delta is an array of hashmaps - one for each state
	for(int i = 0; i < m + 1; i++) {
		for(int j = 0; j < SIZE; j++) {
			delta[i][j] = NULL;
		}
	}

	// PREPROCESSING

	for(int q = 0; q < m + 1; q++) { // for each state from [0, 1, ..., m] 
		for(int j = 0; j < m; j++) {// for each symbol in pattern (symbols, that don't appear in pattern 
					    // will cause a transition to state 0)
			if(find(delta[q], SIZE, pat[j]) == NULL) {
				k = (q + 1 > m) ? m : q + 1;
				succ = 0;
				while(k > 0 && succ == 0) {
					succ = 1;
					if(pat[k-1] != pat[j]) { // last symbol doesn't match
						succ = 0;
					} else {
						for(int i = 0; i < k - 1; i++) {
							if(pat[i] != pat[q + 1 - k + i]) {
								succ = 0;
								break;
							}
						}
					}
					if(succ == 0) k--;
				}
				add_state(delta[q], SIZE, pat[j], k); //delta(q, a(=pat[j])) = k
			}
		}
	}	

	// INPUT PROCESSING

	unsigned int c;
	int q = 0, p = 0;
	while((c = get_utf(fd)) != (unsigned int)'\0' && !(fd == 1 && c == (unsigned int)'\n')) {
		if((q = get_state(delta[q], SIZE, c)) == m) {
			printf("%d ", p - m + 1);
		}
		p++;
	}
	printf("\n");
	return 0;
}
