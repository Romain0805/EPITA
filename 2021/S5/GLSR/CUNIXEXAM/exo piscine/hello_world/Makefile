CC ?= gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic
LIB = libhhello.a
SRC = hello.c hello_main.c
OBJS =$(SRC:.c=.o)

all:$(LIB)

$(LIB): $(OBJS)
$(OBJS): $(SRC)

check:
	$(CC) $(CFLAGS) $(LIB) $(OBJS)

clean:
	$(RM) $(LIB) $(OBJS) a.out

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.a:
	$(CC) $(CFLAGS) -shared -o $(LIB) $(OBJS)

.PHONY: all clean