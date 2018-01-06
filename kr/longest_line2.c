#include <stdio.h>

/*
K&R Page 29
changing ONLY "main"
print the longest arbitrary length line from the given input

I gave up and went to: http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_1:Exercise_16


*/

#define MAXLINE 10

// getline is already defined in stdio.h, so using get_line here:
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

int main(){
        // Cue Mr "386sx", riding to the rescue on a white horse...
        // testing:
        //  - this solution only prints the first MAXLEN of the longest line
        //  - NOT the whole line
        //  - that makes some sense. store the segment in an additional array
        //    and look for something bigger.

        // but is there a way to print the whole line???
        // I'm thinking this is not possible for arbitrary line length without arbitrary storage.
        //   prove me wrong!?!?

        char line[MAXLINE];
        char longest[MAXLINE];

        char temp[MAXLINE];
        int len, max, prevmax, getmore;

        max = prevmax = getmore = 0;
        while((len = get_line(line, MAXLINE)) > 0){
                if(line[len - 1] != '\n'){
                        if(getmore == 0)
                                copy(temp, line);
                        prevmax += len;
                        if(max < prevmax)
                                max = prevmax;
                        getmore = 1;
                }else{
                        if(getmore == 1){
                                if(max < prevmax + len){
                                        max = prevmax + len;
                                        copy(longest, temp);
                                        longest[MAXLINE - 2] = '\n';
                                }
                                getmore = 0;
                        }else if(max < len){
                                max = len;
                                copy(longest, line);
                        }
                        prevmax = 0;
                }
        }
        if(max > 0){
                printf("%s", longest);
                printf("len = %d\n", max);
        }
        return 0;

}
