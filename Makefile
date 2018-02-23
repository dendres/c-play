
CC=gcc
CFLAGS=-m64 -Wall -Wextra -Wpedantic -Wconversion -Wdouble-promotion -Wshadow -Wformat=2 -fsanitize=address -g -l criterion -lm
SRCS=$(wildcard *.c)
NAMES=$(basename $(SRCS))

all: $(NAMES)

.PHONY: check
check:
	cppcheck --enable=all $(filter-out $@,$(MAKECMDGOALS)).c

clean:
	rm -f $(NAMES)


# make a target called "fast" that compiles the supplied file with CFLAGS=-m64 -Wall -Wextra -Wformat=2 -O3 -lm

.PHONY: fast
fast:
	$(CC) -m64 -Wall -Wextra -Wformat=2 -O3 -lm -o $(filter-out $@,$(MAKECMDGOALS)) $(filter-out $@,$(MAKECMDGOALS)).c
