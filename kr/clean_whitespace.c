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
                if (i > 0) // don't print blank lines
                        printf("%s", line);
        }

        return 0;
}

/*
compare to other solutions:
 - could walk backward to set i by puting the conditions in the for loop
   for (i = len-1; (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'); i--)
   and then set the new end of line:
   line[++i] = '\n';
   line[++i] = '\0';

 - should probably set i = len-2 before loop and avoid checking for \n\0:

   while ((len = getline(line, MAXLINE)) > 0) {
        i = len - 2;
        while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
            --i;
        if (i >= 0) {
            line[i+1] = '\n';
            line[i+2] = '\0';
            printf("%s", line);
        }
   }

*/



