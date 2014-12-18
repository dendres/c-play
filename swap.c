
#include <stdio.h>

void swap(int *p1, int *p2)
{
        int b = *p1;
        *p1 = *p2;
        *p2 = b;
}


int main()
{
        int x = 10;
        int y = 20;

        // You must figure out how to call the function correctly!
        swap(&x,&y);

        // Should print out x: 20, y: 10
        printf("x: %d, y: %d\n", x, y);

        return 0;
}




