#include <stdio.h>

/*
K&R Exercise 2-2

Rewrite the following without using && or ||

for (i=O; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
*/


int main() {
        int i;
        const int lim = 1000;
        char c, s[lim];

        while (i < lim - 1) {
                // c = getchar();
                // if (c != '\n'){
                if ((c = getchar()) != '\n'){
                        if (c != EOF) {
                                s[i] = c;
                        }
                }
                ++i;
        }
        printf("%s\n", s);
        return 0;
}


/*
test:
echo hello | ./2-2

compare to others:
 - combine getchar call with check for \n
 - replacing && with * , || with +
   ... confusing, but should work:
    for (i = 0; (i < MAXLINE-1) * ( (c=getchar()) != '\n') * (c != EOF) ; ++i)
*/
