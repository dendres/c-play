
# -g produces debugging information in the OS¹s native format (stabs, COFF, XCOFF, or DWARF 2).
# -ggdb produces debugging information specifically intended for gdb.
# -ggdb3 produces extra debugging information, for example: including macro definitions. -ggdb by itself without specifying the level defaults to
# -ggdb2 (i.e., gdb for level 2).

# how about optimizing???
# -Og reasonable level of optimization while maintaining fast compilation and a good debugging experience
# -O3 lots of optimization. pretty much destroys debugging

CFLAGS=-Wall -Werror -Wextra -g

# splint before building: http://www.splint.org/manual/manual.html ????
# splint +bounds ???

# maybe checkpatch.pl ???  can it be integrated into the editor???


all: ext8

clean:
	rm -f ext8

# https://news.ycombinator.com/item?id=6596855
# https://www.youtube.com/watch?v=z-RJK-NBKXE
#   c should be treated as a "portable assembler" NOT a high level programming language
#   without a deep understanding of the language, its history, and its design goals,
#   you are doomed to fail.
