CC= gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g

OBJS = create.o add.o pop.o del.o print.o

juicy: $(OBJS) main.o
	$(CC) -o heap $^

library: $(OBJS)
	ar csr libheap.a $^

clean:
	$(RM) heap *.o *.a *vgcore*
