#include <stdio.h>

// K&R page 18

int main(){
        /* long next_character; */

        /* next_character = 0; */
        /* while (getchar() != EOF) */
        /*         ++next_character; */

        /* printf("%ld\n", next_character); */


        double next_character;
        for (next_character = 0; getchar() != EOF; ++next_character)
                ; // the body of the loop is missing because the work is done during the condition check

        printf("%.0f\n", next_character);

        return 0;
}
