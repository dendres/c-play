
#include <stdio.h>

void foo(void)
{
        int a = 3;
        ++a;
        printf("%d\n", a);
}

int main(void)
{
        foo();
        foo();
        foo();
        return 0; /* had to add this */
}

/*


deep2.c:16: error: control reaches end of non-void function   ????????

actually prints "4" 3 times... as expected... 

*/

