
#include <stdio.h>

int main(void)
{
        return 0;
}

// heap:

// "the heap" for memory allocation in c... is completely unrelated to the Heap data structure ?????
// c never puts variables on the heap automatically???... stdlib.h malloc, realloc, free, brk/sbrk, mmap ???
// The heap area is shared by all threads, shared libraries, and dynamically loaded modules in a process.


// bss: 'Block Started by Symbol' or 'Better Save Space'
// bss gets zeroed out when the program executes ???
// http://en.wikipedia.org/wiki/.bss
//  part of the data segment containing statically-allocated variables
//  represented solely by zero-valued bits when execution begins
//  In C, statically-allocated objects without an explicit initializer are initialized to zero ???


/*
This is an over-simplification,
but for pedagogy's sake,
you can imagine that your program actually looks like this:

bss
{
  int uninit_global_var;
}

data
{
  int init_global_var;
}

rodata
{
  5;
}

int start_of_program (void) // called by OS
{
  memset(bss, 0, bss_size);
  memcpy(data, rodata, data_size);

  return main(); 
}

data:4 bss:4

Embedded systems with true non-volatile memory will work exactly like the above code, while RAM-based systems may solve the data initialization part differently. bss works the same on all systems.
}
*/
