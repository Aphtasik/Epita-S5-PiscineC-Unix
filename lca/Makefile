CC=gcc
CFLAGS= -Werror -Wextra -Wall -std=99 -pedantic
LDFLAGS= -lcriterion

all: main.o lca.o
	$(CC) $^

check: test.o lca.o
	$(CC) $^ $(LDFLAGS)
	./a.out

clean:
	$(RM) *.o a.out
