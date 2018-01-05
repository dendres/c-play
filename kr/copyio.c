#include <stdio.h>

int main(){
        int character; // why is this an int?????
        /*
          character must be big enough to hold any value returned by getchar()
          EOF is bigger than a char
          so to test for EOF, int or larger must be used
         */

        /* while (character != EOF){ */
        /*         putchar(character); */
        /*         character = getchar(); */
        /* } */

        while ( (character = getchar()) != EOF)
                putchar(character);

        return 0;
}
