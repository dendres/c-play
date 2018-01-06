#include <stdio.h>

/*
K&R Exercise 1-19
reverse each line of input
using a function reverse(s)
*/

#define MAXLINE 1000


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


void strip_newline(char s[]) {
        int i;
        i = 0;
        while (s[i] != '\0') {
                if (s[i] == '\n') {
                        s[i] = '\0';
                        break;
                }
                ++i;
        }
}


void reverse(char s[]) {
        int i, j, t;

        // find the length
        for (j = 0; s[j] != '\0'; ++j)
                ;
        --j;

        // swap characters
        for (i = 0; i < j; i++) {
                t = s[i];
                s[i] = s[j];
                s[j] = t;
                --j;
        }
}


int main(){
        int len;
        char line[MAXLINE];

        while ((len = get_line(line, MAXLINE)) > 0) {
                strip_newline(line);
                reverse(line);
                printf("%s\n", line);
        }
        return 0;
}


/*
http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_19
 - more concise length finding:
   for (j = 0; s[j] != '\0'; ++j)
        ;
   --j;

and no need to have a temp copy of the whole array... just need a temp character
    for (i = 0; i < j; i++) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        --j;
    }

*/
