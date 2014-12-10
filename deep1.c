
#include <stdio.h>

int main(void)
{
// stupid.c:8: error: operation on ‘i’ may be undefined
// stupid.c:8: error: operation on ‘i’ may be undefined

        int v[] = {0,2,4,6,8};
        int i = 1;
        int n = i + v[++i] + v[++i];
        printf("%d\n", n);
}
