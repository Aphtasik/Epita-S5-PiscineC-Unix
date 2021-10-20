CC=gcc
CFLAGS= -Wall -Wextra -Werror -pedantic -std=c99 -g

all: dlist.o
	$(CC) $^ 

library: dlist.o
	ar rcs libdlist.a $^

clean:
	$(RM) *.o a.out
