CC=gcc
CFLAGS= -Wall -Werror -std=c99 -Wextra -pedantic -D_XOPEN_SOURCE=700 -g

all: evaluate.o parser.o main.o
	$(CC) $^

clean:
	$(RM) *.o a.out
