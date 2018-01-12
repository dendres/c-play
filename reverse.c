#include <string.h>
#include <criterion/criterion.h>

int* revR (int* array, int n);

/*
to avoid the need to figure out how to allocate an appropriately sized array
reverse array in place
*/
int* revR(int* array, int n)
{
        int i, j, temp;

        for (i = 0, j = n - 1; i < j; i++, j--) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
        }

        return array;
}


int* revR2(int* array, int n)
{
        int i, j;
        int *out = (int *) malloc(sizeof(int) * n);

        for (i = 0, j = n - 1; i < j; i++, j--) {
                out[i] = array[j];
        }

        return array;
}



Test (Reverse_array, should_pass_all_the_tests_provided)
{
        cr_assert(!memcmp (revR (0, 0), 0, 0));
        cr_assert(!memcmp (revR ((int[]){1}, 1), (int[]){1}, 1*sizeof(int)));
        cr_assert(!memcmp (revR ((int[]){1,2}, 2), (int[]){2,1}, 2*sizeof(int)));
}


/*
compare to others:
int *out = (int *) malloc(sizeof(int) * n);

XXX revR2 is failing... learn malloc!

*/
