CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic

OBJS = create.o add.o pop.o del.o print.o
BIN = create add pop del print

all: $(BIN)

$(BIN): $(OBJS)

clean:
	$(RM) $(BIN) $(OBJS)
