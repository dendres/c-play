#include <stdio.h>

/*
K&R Exercise 1-19
reverse each line of input
using a function reverse()
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
        while( (to[i] = from[i]) != '\0')
                ++i;
}


// reverse the character string s in place
void reverse(char s[]) {

        char temp[MAXLINE];
        int i, j, slength;

        // find the length
        slength = 0;
        while (s[slength] != '\0')
                ++slength;

        // copy into temp backward
        i = 0;
        j = slength - 1;
        while (i <= slength ) {
                temp[i] = s[j];
                ++i;
                --j;
        }

        copy(s, temp);
}

int main(){
        int i, len;
        char line[MAXLINE];
        char l2[MAXLINE];

        while ((len = get_line(line, MAXLINE)) > 0) {

                // strip the \n before sending to reverse
                i = 0;
                while (line[i] != '\n') {
                        l2[i] = line[i];
                        ++i;
                }

                reverse(l2);

                printf("%s\n", l2);
        }
        return 0;
}


