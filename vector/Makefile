CC=gcc
CFLAGS = -Wextra -Wall -pedantic -std=c99 -g

all: vector.o
	ar csr libvector.a $^

test: vector.o
	$(CC) $^

clean:
	$(RM) *o a.out
