
CC=gcc
CFLAGS=-m64 -Wall -Wextra -Wpedantic -Wconversion -g
SRCS=$(wildcard *.c)
NAMES = $(basename $(SRCS))

all: $(NAMES)

clean:
	rm -f $(NAMES)
