#include <stdio.h>

/*
K&R Exercise 1-21
replace spaces with tabs and maintain spacing

stuck. skipping to solutions.
... most of the solutions I found also seem wrong???? skipping this for now


XXX all broken
*/

# define MAXLINE 1000
# define SPACE ' '
# define TAB '\t'
# define NULLC '\0'
# define TABSTEP 8

void copy(char to[], char from[]){
        int i;
        i = 0;
         while( (to[i] = from[i]) != '\0')
                ++i;
}


int get_line(char s[], int lim) {
        int c, i;

        for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}


// takes a \0 terminated character array
// and replaces tabs with the correct number of tabs and spaces
void entab_line(char line[]) {
        int i, j, blank_start, spaces;
        char out[MAXLINE];

        // detect a string of spaces that can fit in a tabstep

        // count number of spaces
        // check if this is a tabstop boundary
        // if it is, go back n and write spaces

        for (i = 0, blank_start = 0; line[i] != NULLC; ++i) {
                if (line[i] = SPACE) {

                }
                spaces = (TABSTEP - (i % TABSTEP) );
        }
        out[j] = NULLC;
        copy(line, out);
}


int main() {
        int len;
        char line[MAXLINE];

        while ((len = get_line(line, MAXLINE)) > 0) {
                detab_line(line);
                printf("%s", line);
        }

        return 0;
}

/*
test:

echo -e "1       234     56      78" | ./entab  # should insert only tab characters
echo -e "a      b" | ./entab # should insert spaces
echo -e "a        b" | ./entab # should insert a tab and one space




*/

