#include <stdio.h>

/*
K&R Exercise 1-17
print any line longer than 80 characters
*/

// store up to the first LINEMIN characters
// until you know if the line is long enough
#define LINEMIN 5

int main(){
        int character;
        int i, j;
        char line_start[LINEMIN];

        i = 0;
        while ((character = getchar()) != EOF) {
                if (i < LINEMIN) {
                        line_start[i] = character;
                } else if ( i == LINEMIN ) {
                        for (j = 0; j < LINEMIN; ++j) {
                                putchar(line_start[j]);
                        }
                        putchar(character);
                } else {
                        putchar(character);

                }
                i++;
                if (character == '\n')
                        i = 0;
        }
        return 0;
}


