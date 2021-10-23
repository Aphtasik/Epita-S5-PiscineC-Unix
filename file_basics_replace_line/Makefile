CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99 -g -fsanitize=address

all: replace_line.o
	$(CC) $^

clean:
	$(RM) *.o a.out vgcore*
