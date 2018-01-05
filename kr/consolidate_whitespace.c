#include <stdio.h>

/*
K&N page 20 Exercise 1-9:
 - copy input to output, but replace multiple blanks by a single blanks
 - I'm assuming this means ' ' only and not all whitespace like \t\n etc...
*/

int main(){
        // first copy output to input

        int character;
        int last_character;

        while(character != EOF){

                if(last_character == ' '){
                        if(character != ' ') putchar(character);
                } else {
                        putchar(character);
                }

                last_character = character;
                character = getchar();
        }

        return 0;
}


