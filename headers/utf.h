#include <unistd.h>

#ifndef UTF_H
#define UTF_H

/**
 * Decodes the length (in bytes) of a UTF-8 encoded character from its first byte val.
 */
int utf_bytes(unsigned char val);

/**
 * Reads a single UTF-8 encoded character from the descriptor fd and returns its representation 
 * as unsigned int.
 */
unsigned int get_utf(int fd);

#endif
