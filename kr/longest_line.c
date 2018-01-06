#include <stdio.h>

/*
K&R Page 29
print the longest line from the given input
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

void copy(char to[], char from[]){
        int i;
        i = 0;
        // shouldn't this rely on walking the lengths of the arrays
        // and not looking for a terminating character
        // that may or may not be there?
        while( (to[i] = from[i]) != '\0')
                ++i;
}

int main(){
        int len;
        int max;
        char line[MAXLINE];
        char longest[MAXLINE];

        max = 0;
        while((len = get_line(line, MAXLINE)) > 0)
                if (len > max) {
                        max = len;
                        copy(longest, line);
                }
        if(max > 0)
                printf("%s", longest);
        return 0;
}
