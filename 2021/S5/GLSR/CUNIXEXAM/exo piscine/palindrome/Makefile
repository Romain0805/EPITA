CC ?= gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic
LIB = libstudent.so
OBJS = palindrome.o main.o

all: $(LIB)

$(LIB): $(OBJS)

check:
	$(CC) $(CFLAGS) $(LIB) $(OBJS)

clean:
	$(RM) $(LIB) $(OBJS) a.out

.PHONY: all clean

%.so:
	$(CC) -shared -o $@ $^
