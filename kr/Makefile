

# try to prevent implicit type conversion:
# -Wconversion
#  Warn for implicit conversions that may alter a value. This includes conversions between
#  real and integer, like "abs (x)" when "x" is "double"; conversions between signed and
#  unsigned, like "unsigned ui = -1"; and conversions to smaller types, like "sqrtf (M_PI)".
#  Do not warn for explicit casts like "abs ((int) x)" and "ui = (unsigned) -1", or if the
#  value is not changed by the conversion like in "abs (2.0)".
#
# -Wdouble-promotion
#  Give a warning when a value of type "float" is implicitly promoted to "double".
#
# -Wnarrowing ??

# https://kristerw.blogspot.com/2017/09/useful-gcc-warning-options-not-enabled.html
# -Wduplicated-cond ??
# -Wduplicated-branches
# -Wlogical-op
# -Wrestrict ??
# -Wuseless-cast ??
# -Wjump-misses-init ??
#
# -Wshadow
#  Warn whenever a local variable or type declaration shadows another variable, parameter,
#  type, or class member (in C++), or whenever a built-in function is shadowed
#
# -Wformat=2
#  Enable additional format checks for printf et al.


# -Wpointer-arith
# -Wcast-qual
# -Wstrict-prototypes
# -Wmissing-prototypes
# -O2 # there are warnings that are only generated when the code is optimized

# -fsanitize=address   https://github.com/google/sanitizers/wiki/AddressSanitizer

CC=gcc
CFLAGS=-m64 -Wall -Wextra -Wpedantic -Wconversion -Wdouble-promotion -Wshadow -Wformat=2 -g -fsanitize=address -l criterion -lm
SRCS=$(wildcard *.c)
NAMES=$(basename $(SRCS))

all: $(NAMES)

clean:
	rm -f $(NAMES)
