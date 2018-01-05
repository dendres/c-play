#include <stdio.h>

/*
K&R page 13
reverse the Farenheit-Celsius table
*/

int main() {
        float fahr, celsius;
        int lower, upper;
        int step;

        lower = -20;
        upper = 100;
        step = 20;


        printf("Celsius Fahrenheit\n");

        celsius = lower;
        while (celsius <= upper) {
                fahr = celsius / (5.0/9.0) + 32.0;
                printf("%8.2f %8.2f\n", celsius, fahr);
                celsius = celsius + step;
        }

        return 0;
}
