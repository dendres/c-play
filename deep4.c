
#include <stdio.h>

int foo(int a) {
        printf("%d", a);
        return a;
}

int bar(int a, int b) {
        printf("bar %d, %d", a, b);
        return a + b;
}

int main(void) {
        int i = foo(3) + foo(4);
        printf("%d\n", i);

        int j = bar(foo(3), foo(4));
        printf("%d\n", j);
        return 0;
}

/*
347
347  ... XXX but get 437 ????

*/
