#include <stdio.h>
#include <ctype.h>
#include <criterion/criterion.h>


/*
K&R page 71
*/
double atof1(char s[])
{
        int i, sign;
        double val, power;
        val = 0.0;
        power = 0.0;

        for (i = 0; isspace(s[i]); i++) /* skip whitespace */
                ;

        sign = (s[i] == '-') ? -1 : 1;

        if (s[i] == '+' || s[i] == '-')
                i++;

        for (val = 0.0; isdigit(s[i]); i++)
                val = 10.0 * val + (s[i] - '0');

        if (s[i] == '.')
                i++;

        for (power = 1.0; isdigit(s[i]); i++) {
                val = 10.0 * val + (s[i] - '0');
                power *= 10.0;
        }

        return sign * val / power;
}


/*
K&R Exercise 4-2

extend atof to handle scientific notation of the form
123.45e6
-123.45e-6
1E9
-1E-3

*/
double atof2(char s[])
{
        int i, sign, exponent_sign;
        double val, power, exponent_number, exponent_power;
        val = 0.0;
        power = 0.0;

        for (i = 0; isspace(s[i]); i++) /* skip whitespace */
                ;

        /*set sign and skip past sign characters*/
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
                i++;

        for (val = 0.0; isdigit(s[i]); i++)
                val = 10.0 * val + (s[i] - '0');

        if (s[i] == '.')
                i++;

        for (power = 1.0; isdigit(s[i]); i++) {
                val = 10.0 * val + (s[i] - '0');
                power *= 10.0;
        }

        if(s[i] == 'e' || s[i] == 'E')
                i++;

        exponent_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
                i++;

        for (exponent_number = 0.0; isdigit(s[i]); i++)
                exponent_number = 10 * exponent_number + (s[i] - '0');

        exponent_power = 1;
        if (exponent_sign < 1) {
                for(i = 0; i < exponent_number; i++) {
                        exponent_power *= 0.1;
                }
        } else {
                for(i = 0; i < exponent_number; i++) {
                        exponent_power *= 10;
                }
        }

        return (sign * val / power) * exponent_power;
}


Test(scientific_notation, normal)
{
        double x = 0;
        cr_assert((x = atof2("0")) == 0.0, "Expected 0, but got %f", x);
        cr_assert((x = atof2("-0")) == 0.0, "Expected 0, but got %f", x);
        cr_assert((x = atof2("1")) == 1.0, "Expected 1.0, but got %f", x);
        cr_assert((x = atof2("-1")) == -1.0, "Expected -1.0, but got %f", x);
        cr_assert((x = atof2("12345.6789")) == 12345.6789, "Expected 12345.6789, but got %f", x);
        cr_assert((x = atof2("-12345.6789")) == -12345.6789, "Expected -12345.6789, but got %f", x);
}


Test(scientific_notation, enotation)
{
        double x = 0;
        cr_assert((x = atof2("0e0")) == 0.0, "Expected 0, but got %f", x);
        cr_assert((x = atof2("0e5")) == 0.0, "Expected 0, but got %f", x);
        cr_assert((x = atof2("0e-5")) == 0.0, "Expected 0, but got %f", x);
        cr_assert((x = atof2("-0e-5")) == 0.0, "Expected 0, but got %f", x);

        cr_assert((x = atof2("1e0")) == 1.0, "Expected 1, but got %f", x);
        cr_assert((x = atof2("1e-0")) == 1.0, "Expected 1, but got %f", x);
        cr_assert((x = atof2("1e1")) == 10.0, "Expected 10, but got %f", x);
        cr_assert((x = atof2("1e-1")) == 0.1, "Expected 0.1, but got %f", x);
        cr_assert((x = atof2("-1e-1")) == -0.1, "Expected -0.1, but got %f", x);

        /*comparing small floats was buggy*/
        cr_assert_float_eq(x = atof2("1e-2"), 0.01, 0.000000001, "Expected 0.01, but got %9.9e", x);
        cr_assert_float_eq(x = atof2("1e-9"), 0.000000001, 0.000000001, "Expected 0.000000001, but got %9.9e", x);
        cr_assert_float_eq(x = atof2("1e-15"), 0.000000000000001, 0.000000000000001, "Expected 0.000000001, but got %9.9e", x);

        cr_assert((x = atof2("1e2")) == 100, "Expected 100, but got %f", x);
        cr_assert((x = atof2("1.234e3")) == 1234, "Expected 1234, but got %f", x);
        cr_assert((x = atof2("1.234e16")) == 12340000000000000, "Expected 12340000000000000, but got %f", x);

}

