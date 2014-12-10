
#include <stdio.h>

void foo(void)
{
        int a;
        ++a;
        printf("%d\n", a);
}

int main(void)
{
        foo();
        foo();
        foo();
        return 0;
}

/*
trying out the -O optimize flag

$ gcc -O -Wall -Werror -Wextra deep3.c
cc1: warnings being treated as errors
deep3.c: In function ‘foo’:
deep3.c:7: error: ‘a’ is used uninitialized in this function

*/
