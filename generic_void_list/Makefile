CC=gcc
CFLAGS= -Wall -Wextra -Werror -pedantic -std=c99 -g

all: list.o
	$(CC) $^

library: list.o
	ar rcs liblist.a $^

clean:
	$(RM) *.o vgcore* a.out
