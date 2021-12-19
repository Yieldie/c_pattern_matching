#include <stdio.h>
#include <fcntl.h>
#include <utf.h>

#define MAX_LEN	100

int main(int argc, char **argv)
{
	// INITIALIZATION

	int fd = 1, m;
	unsigned int pat[MAX_LEN], u;
	if(argc > 1) {
		fd = open(argv[1], O_RDONLY);
	} 

	m = 0;
    	while((u = get_utf(1)) != (unsigned int)'\n' && u != (unsigned int)'\0' && m < MAX_LEN - 1) {
        	pat[m] = u;
        	m++;
    	}

	// PREPROCESSING
	
	int pi[m];
	int k = 0;
	pi[0] = 0;
	for(int q = 1; q < m; q++) {
		if(pat[q] == pat[k]) {
			pi[q] = ++k;
		} else {
			if(k > 0) {
				k = pi[k - 1];
				q--;
			} else {
				pi[q] = 0;
			}
		}
	}

	// INPUT PROCESSING
	
	unsigned int c;
	int q = 0, p = 0;
	while((c = get_utf(fd)) != (unsigned int)'\0' && !(fd == 1 && c == (unsigned int)'\n')) {
		if(pat[q] == c) {
			q++;
			if(q == m) {
				printf("%d ", p - m + 1);
				q = pi[q - 1];
			}
		} else if(q > 0) {
			q = pi[q - 1];
			if(pat[q] == c) {
				q++;
			} else if(q > 0) {
				q = pi[q - 1];
			}
		}
		p++;
	}
	printf("\n");
	return 0;
}
