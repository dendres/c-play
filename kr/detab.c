#include <stdio.h>

/*
K&R Exercise 1-20
replace tabs with spaces
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
// and modifies it by replacing tab characters with spaces
void detab_line(char line[]) {
        int i, j, k, spaces;
        char out[MAXLINE];

        for (i = 0, j = 0; line[i] != NULLC; ++i, ++j) {
                if (line[i] == TAB) {
                        spaces = (TABSTEP - (j % TABSTEP) ); // cheated here
                        for(k = j; j < (k + spaces); ++j) {
                                out[j] = SPACE;
                        }
                        --j; // have to back up one step after writing all the spaces?????
                } else {
                        out[j] = line[i];
                }
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
these 2 should produce identical spacing:

echo -e "1\t234\t567\t89"
echo -e "1\t234\t567\t89" | ./detab


compare to others:
 - SPACE and TAB as constants
 - comma separated initial conditions in for loop: for(i=0,j=0,k=0)
   and ++j,++j,++k in for loop
*/

