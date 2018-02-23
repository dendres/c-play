#include <stdio.h>
#include <stdlib.h>

int close_compare(int a, int b, int margin)
{
        if (abs(a - b) <= margin)
                return 0;
        if (a > b)
                return 1;
        else
                return -1;
}


/*
return a > b ? 1 : -1;
*/
