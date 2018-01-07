#include <stdio.h>

/*
K&R Exercise 1-20
replace tabs with spaces
*/

# define MAXLINE 1000


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


int main() {
        int i, j, l, len;
        char line[MAXLINE];
        char out[MAXLINE];
        // tabs have to remain in columns every 8 spaces from the beginning of the line
        // so can't look for just any 8 spaces...
        // must look for multiples of 8 starting from beginning of the line

        // had to cheat to get the number of spaces to add = (tab - (i % tab))

        // get a line.
        while ((len = get_line(line, MAXLINE)) > 0) {

                i = 0;
                j = 0;
                while (line[i] != '\0') {
                        if (line[i] == '\t') {
                                out[j] = ' ';
                                l = j + (8 - (j % 8) ) - 1;
                                while (j < l) {
                                        out[++j] = ' ';
                                }
                        } else {
                                out[j] = line[i];
                        }

                        ++i;
                        ++j;
                }

                out[j] = '\0';

                printf("%s", out);
        }

        return 0;
}

