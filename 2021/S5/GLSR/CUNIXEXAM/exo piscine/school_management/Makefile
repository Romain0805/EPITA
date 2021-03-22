CC ?= gcc

CFLAGS= -std=c99 -Wall -Wextra -Werror -pedantic

SRC = school_man.c \
    school_man2.c \
    school_man3.c


OBJS= $(SRC:.c=.o)

libschool.a: $(OBJS)
	ar csr -l libschool.a $(OBJS)

EXEC= school_management

all: libschool.a

check: $(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

$(LIB): $(OBJS)

clean:
	$(RM) $(OBJS) *.a

.PHONY : all clean
