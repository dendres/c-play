#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void reverse(char s[])
{
        int i, j;
        char t;

        /* find the length */
        for (j = 0; s[j] != '\0'; ++j)
                ;
        --j;

        /* swap ends */
        for (i = 0; i < j; i++) {
                t = s[i];
                s[i] = s[j];
                s[j] = t;
                --j;
        }
}


/*
K&R 3-5
convert an integer to an arbitrary base

no one seems to be converting negative numbers to 2's complement binary
... so I won't either.

preserving '-' sign like the previous exercise instead
*/
void itob(int n, char s[], int b)
{
        int i, sign;
        char chars[] = "0123456789abcdefghijklmnopqrstuvwxyz";

        if ( b < 2 || b > 36 ) {
                fprintf(stderr, "itob cannot use base %d\n", b);
                exit(EXIT_FAILURE);
        }

        i = 0;
        sign = n;

        do {
                s[i++] = chars[abs(n % b)];
        } while (abs(n /= b) > 0);

        if (sign < 0)
                s[i++] = '-';

        s[i] = '\0';
        reverse(s);
}


int main()
{
        int i, n, b;
        int numbers[] = {0, 1, -1, INT_MAX, INT_MIN};
        char s[1000];

        for (b = 2; b <= 16; b++) {
                for (i = 0; i < (int)(sizeof(numbers) / sizeof(numbers[0])); i++) {
                        n = numbers[i];
                        itob(n,s,b);
                        printf("n = %d, b = %d, s = %s\n", n, b, s);
                }
        }
        return 0;
}


/*
comparing to others:
 - error if base is not valid
*/
