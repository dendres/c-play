#include <stdio.h>

/*
K&R Page 22
count each digit 0-9, whitespace, and other
*/


int main(){

        int c, i, white_count, other_count;
        int digits[10];

        // initialize all variables including the array
        white_count = other_count = 0;
        for (i = 0; i < 10; ++i)
                digits[i] = 0;

        while ((c = getchar()) != EOF) {
                if (c >= '0' && c <= '9') {
                        ++digits[c-'0'];
                } else if (c == ' ' || c == '\n' || c == '\t') {
                        ++white_count;
                } else {
                        ++other_count;
                }

        }
        printf("digits =");
        for (i = 0; i < 10; ++i)
                printf(" %d", digits[i]);
        printf(", white space = %d, other = %d\n", white_count, other_count);
        return 0;
}
