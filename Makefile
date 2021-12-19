INC_DIR = headers
CC = gcc
CFLAGS = -I$(INC_DIR)

targets = dfa kmp

all: $(targets)

dfa: src/dfa.c src/hashmap.c src/utf.c
	$(CC) $(CFLAGS) -o $@ $^

kmp: src/kmp.c src/utf.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(targets)
