CC=gcc
CFLAGS= -Werror -Wextra -Wall -std=c99 -pedantic -g
LDFLAGS= -lcriterion

all: lca.o
	$(CC) $^

check: lca.o
	$(CC) $^ $(LDFLAGS)
	./a.out

clean:
	$(RM) *.o a.out
