CC= gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic

OBJS = create.o add.o pop.o del.o print.o

all: $(OBJS) 
	$(CC) -o heap $^

library: $(OBJS)
	ar csr libheap.a $^

clean:
	$(RM) heap *.o *.a
