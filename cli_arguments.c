
#include <stdio.h>

/* argc keeps a count of the number of arguments
   argv is an arry of the argument strings (null-terminated character arrays)
   the return value is an integer
*/
int main(int argc, char *argv[])
{
        int i = 0;

        for(i = 1; i < argc; i++) {
                printf("arg %d: %s\n", i, argv[i]);
        }

        return 0;
}
