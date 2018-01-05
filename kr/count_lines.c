#include <stdio.h>

// K&R page 19
// count input lines

int main(){
        int character, next_line;

        next_line = 0;

        while ((character =  getchar()) != EOF)
                if (character == '\n') // character constant 'x': integer value for the character x
                        ++next_line;

        printf("%d\n", next_line);

        return 0;
}
