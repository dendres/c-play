#include <stdio.h>

/*
output lines to test applications that read lines
*/

#define MAXINT 2147483647


int main(){
        printf("hello\n");
        printf("\n");
        int i;
        for (i = 0; i < MAXINT; i++)
                putchar('x');
        putchar('\n');
        printf("there\n");
        return 0;
}
