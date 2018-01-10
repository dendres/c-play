#include <stdio.h>
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
K&R Exercise 3-4

first showing what the example itoa does not handle
and that -(2^wordsize-1) == INT_MIN from limits.h

*/
void itoa(int n, char s[])
{
        int i, sign;

        if ((sign = n) < 0)
                n = 0 - n;

        i = 0;
        do {
                s[i++] = (char)(n % 10 + (int)'0');
        } while ( (n /= 10) > 0);

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
