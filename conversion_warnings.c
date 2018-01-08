#include <stdio.h>


int foo (int x){
        return x + 5;
}


int bar (long x) {
        /* x is implicitly converted to type int. -Wconversion should flag this */
        return foo(x);

}


int main(){
        int y;

        y = bar(5.0);
        printf("y = %d\n", y);

        return 0;
}
