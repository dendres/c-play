
CC=gcc
CFLAGS=-m64 -Wall -Wextra -Wpedantic -Wconversion -Wdouble-promotion -Wshadow -Wformat=2 -g -l criterion -lm
SRCS=$(wildcard *.c)
NAMES=$(basename $(SRCS))

all: $(NAMES)

clean:
	rm -f $(NAMES)
