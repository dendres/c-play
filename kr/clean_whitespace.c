#include <stdio.h>

/*
K&R Exercise 1-18
remove trailing blanks and tabs
delete empty lines
cutting off lines at MAXLINE
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

int main(){
        int c, i, len;
        char line[MAXLINE];

        // get a line
        // walk the line backwards untill a non-whitespace character is found
        // set \n\0

        while ((len = get_line(line, MAXLINE)) > 0) {
                for (i = len; i >= 0; --i){
                        c = line[i];
                        if (c != ' ' && c != '\t' && c != '\n' && c != '\0') {
                                line[i+1] = '\n';
                                line[i+2] = '\0';
                                break;
                        }
                }
                printf("%s", line);
        }

        return 0;
}
