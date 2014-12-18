
#include <stdio.h>

int main()
{
        // reference:
        // - http://boredzo.org/pointers/
        // Understanding and Using C Pointers book

        /*
          types of ambiguity in the C specification:
          implementation-defined
          unspecified
          undefined
          locale-specific
         */



        // * is the dereference operator
        // & is the address_of operator


        // notes on pointer declaration and operator precedence
        // int* ptr_a, ptr_b;  // ptr_a is int*, but ptr_b is NOT
        // int *ptr_a, *ptr_b; // this declares 2 variables of type int*
        // int ptr_b, *ptr_a; // it is less ambiguous to put the non-pointer first

        /*
          // Whitespace does not matter when declaring a pointer.
          // the following are all equivalent:
          int* pi;
          int * pi;
          int *pi;
          int*pi;
         */

        /*
        int *a;
        int *b[9];
        int (*c)[9];
        */





        // how to initialize an array literal as a pointer???
        // int *ages = (int[]){23, 43, 12, 89, 2};

        // "decaying"... the array “decays” to a pointer
        // Most usages of array are equivalent to if array had been declared as a pointer ???
        // Decaying is an implicit &; array == &array == &array[0].
        // In English, these expressions read “array”, “pointer to array”, and “pointer to the first element of array” (the subscript operator, [], has higher precedence than the address-of operator). But in C, all three expressions mean the same thing.


        // The subscript operator (the [] in array[0]) has nothing to do with arrays.
        // The definition of the subscript operator [] is that E1[E2] is identical to (*((E1)+(E2))).
        int an_array[] = {45, 67, 89};
        int *array_ptr = &an_array[1];
        printf("%i\n", array_ptr[1]);


        // If arr is a pointer to arr[ 0 ] then arr + i is a pointer to arr[ i ]

        // are c arrays guaranteed to be contiguious in memory????

        // char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};

        /*
        int count = sizeof(*ages) / sizeof(int);
        printf("count = %d\n", count);


        int i = 0;

        int *cur_age = ages;
        char **cur_name = names;

        printf("--- normal array element access ---\n");

        for(i =0; i < count; i++) {
                printf("%s has %d years alive.\n", names[i], ages[i]);
        }

        printf("--- increment the pointer address to get the next array element??? ---\n");

        for(i = 0; i < count; i++) {
                printf("%s is %d years old.\n", *(cur_name+i), *(cur_age+i)); // how can this possibly work?
        }

        printf("--- array element access seems to work transparently through pointers??? ---\n");

        for(i = 0; i < count; i++) {
                printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
        }

        printf("--- some fucked up pointer math ???? ---\n");
        // assignment of array to pointer... sets cur_name to the value of the first element???
        for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
                // %p prints the address of the pointer
                printf("cur_name = %p, cur_age = %p \n", cur_name, cur_age);

                printf("%s lived %d years so far.\n", *cur_name, *cur_age);
        }

        // bonus:  Try to make cur_age point at names
        // printf("*cur_age = %p, *names = %p\n", cur_age, names);
        // cur_age = (int)*names;
        // prevented by Werror... try a few techniques ???

        */

        // look how the addresses are incremented by 8 and 4...
        // even though the loop above is incrementing by 1
        // where does the logic live that knows about 8 and 4 ???
        //   sounds like it's implemented in the pointer object
        //   which is why it's so important to specify the type of a pointer
        //   the type provides the offset for each increment/decrement
        //   XXX find the c99 and c11 spec for this!!!


        /* cur_name = 0x7fffc09cffb0, cur_age = 0x7fffc09cffe0 */
        /* Alan lived 23 years so far. */
        /* cur_name = 0x7fffc09cffb8, cur_age = 0x7fffc09cffe4 */
        /* Frank lived 43 years so far. */
        /* cur_name = 0x7fffc09cffc0, cur_age = 0x7fffc09cffe8 */
        /* Mary lived 12 years so far. */
        /* cur_name = 0x7fffc09cffc8, cur_age = 0x7fffc09cffec */
        /* John lived 89 years so far. */
        /* cur_name = 0x7fffc09cffd0, cur_age = 0x7fffc09cfff0 */


        return 0;
        // what do I think a pointer does?
        //  it's the memory address of a data structure... right?


        // ages[i] = I want the integer in ages that is at address i
        // ages = the address where all of these integers start

        // how does incrementing the address of ages know to move 4 bytes ahead instead of 1 byte ahead?

}
