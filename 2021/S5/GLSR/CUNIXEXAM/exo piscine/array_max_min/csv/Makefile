CC ?= gcc

CFLAGS= -std=c99 -Wall -Wextra -Werror -pedantic

OBJS= csv.o

all:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o csv

clean:
	$(RM) $(OBJS)

.PHONY : all clean
