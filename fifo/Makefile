CC=gcc
CFLAGS= -Wall -Wextra -Werror -pedantic -std=c99 -g

all: fifo.o
	$(CC) $^

library: fifo.o
	ar rcs libfifo.a $^

clean:
	$(RM) *.o vgcore* a.out
