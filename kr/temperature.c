#include <stdio.h>

/*
K&R page 9
print Farenheit-Celsius table for fahr = 0, 20, ... 300
*/

int main() {
        // all variables must be declared before use
        float fahr, celsius;
        int lower, upper;
        int step;

        lower = -20;
        upper = 100;
        step = 20;


        printf("Fahrenheit Celsius\n");

        fahr = lower; // cast to float??
        while (fahr <= upper) { // comparing int to float?
                // celsius = 5 / 9 * (fahr - 32)
                // celsius would always be zero because the
                // integer division would be truncated to zero

                // celsius = 5 * (fahr - 32) / 9;
                // printf("%3d %6d\n", fahr, celsius);

                celsius = (5.0/9.0) * (fahr - 32.0);
                printf("%8.2f %8.2f\n", fahr, celsius);

                fahr = fahr + step;
        }

        return 0;
}
