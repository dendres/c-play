
#include <stdio.h>

int main()
{
        // how to initialize an array literal as a pointer???
        int *ages = (int[]){23, 43, 12, 89, 2};


        // In C, arrays have a strong relationship to pointers
        // The C standard defines that numbers[0] is just syntactic sugar for *(numbers + 0)
        //    arr[ i ] == * ( arr + i )

        // If arr is a pointer to arr[ 0 ] then arr + i is a pointer to arr[ i ]
        //   what knows to transform arr + i into arr + i * len(type(arr)) ??? or is that even what happens???

        // are c arrays contiguious in memory????


        // char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};

        int count = sizeof(*ages) / sizeof(int);
        printf("count = %d\n", count);

        /*
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
