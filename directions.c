#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>

bool opposite(char *direction1, char *direction2)
{
        char d1 = direction1[0];
        char d2 = direction2[0];

        if (d1 == 'N' && d2 == 'S')
                return true;
        if (d1 == 'S' && d2 == 'N')
                return true;
        if (d1 == 'E' && d2 == 'W')
                return true;
        if (d1 == 'W' && d2 == 'E')
                return true;

        return false;
}


/* arr: directions to reduce, sz: size of arr, lg size of returned array
   function result will be freed
*/
char** dirReduc(char **arr, int sz, int *lg)
{
        int i, j;
        char *a, *b;
        char **out = malloc((size_t)sz * sizeof(char*));

        i = j = 0;
        while (i < sz) {
                a = arr[i];
                b = (i < sz - 1) ? arr[i + 1] : "";
                if (opposite(a, b))
                        i += 2;
                else
                        out[j++] = arr[i++];
        }

        if( sz == j) { /* quit if no directions were removed */
                *lg = sz;
                return out;
        }

        *lg = j;
        return dirReduc(out, j, lg);
}


/*
compare to others:
 - solve the fencepost problem by
   comparing the last element to a known invalid string ""
   to avoid making a separate copy of the logic
   char* d = i < sz - 1 ? arr[i + 1] : "";
 - the main loop can be maid to handle the (sz < 2) condition, so no extra exit is required
*/


void dotest(char** arr, int sz, char* expr) {
        int lg = -1;
        int i;
        char** act = dirReduc(arr, sz, &lg);


        printf("got: ");
        for (i = 0; i < lg; i++) {
                printf("%s,", act[i]);
        }
        printf("\n expected: %s\n\n", expr);
}

Test(dirReduc, ShouldPassAllTheTestsProvided) {
        {
                char* d1[7] = {"NORTH1", "SOUTH2", "SOUTH3", "EAST4", "WEST5", "NORTH6", "WEST7"};
                dotest(d1, 7,  "{WEST7}");
        }


        {
                char* d1[4] = {"NORTH", "WEST", "SOUTH", "EAST"};
                dotest(d1, 4,  "{NORTH, WEST, SOUTH, EAST}");
        }
        {
                char* d1[10] = {"NORTH1", "WEST2", "SOUTH3", "EAST4", "NORTH5", "WEST6", "SOUTH7", "EAST8", "SOUTH9", "NORTH10"};
                dotest(d1, 10,  "{NORTH1, WEST2, SOUTH3, EAST4, NORTH5, WEST6, SOUTH7, EAST8}");
        }
        {
                char* d1[4] = {"NORTH", "SOUTH", "WEST", "EAST"};
                dotest(d1, 4,  "{}");
        }

}
