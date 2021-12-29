INC_DIR = headers
CC = gcc
CFLAGS = -I $(INC_DIR)

targets = dfa kmp

all: $(targets)

dfa: src/dfa.c utf.o hashmap.o
	$(CC) $(CFLAGS) -o $@ $^

kmp: src/kmp.c utf.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm -f *.o

cleanall: clean
	rm -f $(targets)
