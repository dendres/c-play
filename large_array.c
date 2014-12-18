
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
// reduce the size eventually it produces a Segmentation fault and core dump
//   the size required to produce the Segmentation fault is NOT fixed
//     it seems to vary with free memory... what happened to the virtual address space and swap????
//     adding additional swap space doesn't seem to make a difference???
// this appears to be 2^61 -1
int main()
{
        //unsigned long compiler_max = 2305843009213693951ul;
        unsigned long runnable_max = 2095000ul;

        int large_array[runnable_max];

        printf("large_array size = %lu\n", sizeof(large_array));
        return 0;
}

// a[][] = {{1, 2, 3}, {4, 5, 6}};   does this work???
