
#include <stdio.h>

/*
Limit of `size_t' type.
# if __WORDSIZE == 64
#  define SIZE_MAX              (18446744073709551615UL)
# else
#  define SIZE_MAX              (4294967295U)
# endif
*/


// the compiler allows max array of int size of 2305843009213693951ul
// but this gives a core dump on execute ???
// this appears to be 2^61 -1
int main()
{
        unsigned long index_max = 2305843009213693951ul;

        int large_array[index_max];

        printf("large_array size = %lu\n", sizeof(large_array));
        return 0;
}

// a[][] = {{1, 2, 3}, {4, 5, 6}};   does this work???
