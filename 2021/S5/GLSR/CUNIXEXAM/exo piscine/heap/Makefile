# CC is the standard name of the C compiler which will be used.
# By using ?= instead of = to assign a value to CC we are only setting its value
# if it wasn't previsouly set.
CC ?= gcc

# CFLAGS is the standard name for flags to pass to the C compiler.
# Here, we unconditionally set them as the coding style specifies your code
# should compile with these flags only.
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic

# This will be the name of the library we will build with our code (to be able
# to use the `-lstudent` flag we evoked earlier.
LIB = libheap.a

# This is the list of object files we will build from our C source code files.
OBJS = add.o create.o del.o pop.o print.o

EXEC = heap

# This rule (the first one that doesn't start with a `.`) will be the default
# target which will be called if we use `make` without any parameter.
all: $(OBJS)
	ar csr $(LIB) $(OBJS)

check:
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# For the library, we just have to specify its dependencies as it will fall into
# the pattern rule at the end of this Makefile.
# Moreover, library code needs to be Position independant, `-fPIC` allows this
$(LIB): $(OBJS)

# `clean` is the standard name for a rule which cleans all the build files
# produced by the other rules in the Makefile.
# $(RM) will be replaced by `rm  -f`.
clean:
	$(RM) $(LIB) $(OBJS) $(EXEC)

# The .PHONY target contains the names of all targets which don't produce a file
# called like them.
.PHONY: all check clean

# This is a pattern rule which matches all the files ending with `.so`.
# If no explicit rule matches a target name and this does, it will be considered
# as its rule.
%.a:
	$(CC) -fPIC -shared -o $@ $^