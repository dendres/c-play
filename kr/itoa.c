#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

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
K&R Exercise 3-4
make itoa handle INT_MIN on any machine

0 - INT_MIN == INT_MIN == -2147483648
this causes an overflow because 2147483647 is the largest positive integer

handling the positive and negative cases independently

*/
void itoa(int n, char s[])
{
        int i, sign;

        sign = n;
        i = 0;
        do {
                s[i++] = (char)(abs(n % 10) + (int)'0');
        } while ( n /= 10 );

        if (sign < 0)
                s[i++] = '-';

        s[i] = '\0';
        reverse(s);
}


int main()
{
        int i;
        char s1[100];
        int numbers[] = {0, 1, -1, INT_MAX, INT_MIN};

        for (i = 0; i < (int)(sizeof(numbers) / sizeof(numbers[0])); i++) {
                itoa(numbers[i], s1);
                printf("x = %d, s1 = %s\n", numbers[i], s1);
        }
        return 0;
}

/*
compare to others:
 - didn't need stdbool
 - use abs function from stdlib
 - while( (n /= 10) > 0)  is the same as while( n /= 10 ) ?

*/
