#include <utf.h>

int utf_bytes(unsigned char val)
{
	if(val < 128) {
		return 1;
	} else if(val < 224) {
		return 2;
	} else if(val < 240) {
		return 3;
	} else {
		return 4;
	}
}

// As UTF-8 characters are limited to 4-bytes, one can store such character in an integer variable. 
// This function checks the length in bytes of the next character from input, reads the character 
// and returns the corresponding unsigned integer.

unsigned int get_utf(int fd)
{	
	int l, b;
	unsigned int x;
	unsigned char a;
	b = read(fd, &a, 1);
	if(b == 0) 
		return 0;
	l = utf_bytes(a);
	x = a;
	for(int i = 0; i < l - 1; i++) {	
		read(fd, &a, 1);
		x = x << 8;
		x += a;
	}
	return x;
} 
