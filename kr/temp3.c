#include <stdio.h>

/*
K&R page 14
use a for loop
and print the temperatures in reverse order
add symbolic constants with #define
*/

#define LOWER -20
#define UPPER 100
#define STEP 20


int main(){
        int fahrenheit;
        for (fahrenheit = UPPER; fahrenheit >= LOWER; fahrenheit = fahrenheit - STEP)
                printf("%3d %8.2f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
        return 0;
}
