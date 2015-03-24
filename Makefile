CC = gcc
DEBUG = -g
CFLAGS = $(DEBUG)

EXE = double
OBJS = main.o trie.o

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
trie.o: trie.h trie.c
	$(CC) $(CFLAGS) -c trie.c
.PHONY: clean
clean:
	rm -rf $(OBJS) $(EXE)

