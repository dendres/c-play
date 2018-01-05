#include <stdio.h>

/*
K&N page 20
a barebones version of the word counting program wc
*/

#define INSIDE_WORD 1
#define OUTSIDE_WORD 0


int main() {
        int character, line_next, word_next, character_next;
        int state; // state can be INSIDE_WORD or OUTSIDE_WORD

        state = OUTSIDE_WORD;
        line_next = word_next = character_next = 0;
        while((character = getchar()) != EOF) {
                ++character_next;

                if (character == '\n')
                        ++line_next;

                if (character == '\n' || character == '\t' || character == ' ')
                        state = OUTSIDE_WORD;
                else if (state == OUTSIDE_WORD) {
                        state = INSIDE_WORD;
                        ++word_next;
                }
        }

        printf("%d %d %d\n", line_next, word_next, character_next);

        return 0;
}
