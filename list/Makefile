CC=gcc
CFLAGS= -Wall -Wextra -pedantic -std=c99 -g
OBJS=list.o list_print.o main.o

all: list.o list_print.o main.o
	$(CC) $^

clean:
	$(RM) *.o a.out vgcore*
