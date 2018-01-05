#include <stdio.h>

/*
K&R Exercise 1-12
print input one word per line
... assuming here "word" means whitespace separated characters
*/

#define INSIDE_WORD 1
#define OUTSIDE_WORD 0

int main() {

        int c;
        int l;

        while((c = getchar()) != EOF) {
                if (c == '\n' || c == '\t' || c == ' '){
                        if (l != '\n' && l != '\t' && l != ' '){
                                putchar('\n');
                        }
                } else {
                        putchar(c);
                }
                l = c;
        }

        return 0;
}
