CC ?= gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic
LIB = libstudent.so
OBJS = insertion_sort.o insertion_sort_main.o
EXEC = insertion_sort

all:$(LIB)

check:
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

$(LIB): CFLAGS += -fPIC
$(LIB):$(OBJS)

clean:
	$(RM) $(LIB) $(OBJS) $(EXEC)

.PHONY: all check clean

%.so:
	$(CC) -shared -o $@ $^
