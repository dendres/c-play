#include <stdio.h>
#include <limits.h>

/*
K&R Exercise 2-6
not quite sure
*/



/*
https://en.wikipedia.org/wiki/Bitwise_operations_in_C

print decimal, octal, hex, and binary forms of an unsigned integer
*/
void showbits(unsigned int x)
{
        int i;
        printf("%u, 0%o, 0x%x, ", x, x, x);
        for (i = (sizeof(int)*8)-1; i>=0; i--)
                (x&(1u<<i)) ? putchar('1') : putchar('0');
        printf("\n");
}

/*
many thanks to the following for explaining getbits:
https://stackoverflow.com/questions/197614/k-r-question-need-help-understanding-getbits-method-in-chapter-2

(x >> (p+one-n))
  moves the desired field to the right end of the word ????????????

~(~zero << n)
  this creates the mask which will choose the bits we want
  ~zero          is all ones
  ~zero << n     left shifts ones over exposing n zeros
  ~(~zero << n)  then inverts this so there are n ones in the right most position

Why not make the mask in place by shifting left and right and then & it with the original x ????


*/
unsigned int getbits(unsigned int x, unsigned int p, unsigned int n)
{
        unsigned int zero = 0;
        unsigned int one = 1;
        return (x >> (p+one-n)) & ~(~zero << n);
}


unsigned int setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y)
{
        /*  coming back to this later*/
}



int main()
{
        unsigned int x = UINT_MAX;
        unsigned int p = 6;
        unsigned int n = 5;
        showbits(x);
        showbits(getbits(x,p,n));
        return 0;
}
