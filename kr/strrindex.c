#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char s[], int lim)
{
        char c;
        int i = 0;

        while (--lim > 0 && (c = (char)getchar()) != EOF && c != '\n')
                s[i++] = c;

        if (c == '\n')
                s[i++] = c;

        s[i] = '\0';

        return i;
}

/* K&R page 69 */
int strindex(char s[], char t[])
{
        int i,j,k;

        for (i = 0; s[i] != '\0'; i++) {
                for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
                        ;
                if (k > 0 && t[k] == '\0')
                        return i;
        }
        return -1;
}

/*
K&R Exercise 4-1
return the position of the rightmost occurrence of t in s
or -1 if there is none

oops... not the position of the last character in t

XXX assuming t happens multiple times, find the last instance in s
   I'll try searching backwards:
*/
int strrindex(char line[], char pattern[])
{
        int i, j, k, match;

        for (i = (int)strlen(line) - 1; i >= 0 ; i--) {
                match = i;
                for (j = i, k = 0; pattern[k] != '\0' ; j++, k++) {
                        if (line[j] != pattern[k]) {
                                match = -1;
                                break;
                        }
                }
                if (match != -1) {
                        return match;
                }

        }
        return match;
}

/*
found this one here: http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_4:Exercise_1
only a tiny change from the original function on page 69
but starts at the beginning and traverses the whole string
... instead of starting at the end and stopping at the first match
*/
int strrindex2(char s[], char t[])
{
        int i,j,k, match;

        match = -1;
        for (i = 0; s[i] != '\0'; i++) {
                for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
                        ;
                if (k > 0 && t[k] == '\0')
                        match = i;
        }
        return match;
}


int main ()
{
        char pattern[] = "ould";
        char line[MAXLINE];
        int match;

        while (get_line(line, MAXLINE) > 0) {
                match = strrindex(line, pattern);
                if (match == -1) {
                        printf("|%s| not found in |%s|", pattern, line);
                } else {
                        printf("in |%s| found |%s| starting at %d\n", line, pattern, match);
                }
        }

        return match;
}
