#include <criterion/criterion.h>
#include <stdlib.h>
#include <ctype.h>


char *accum(const char *source)
{
        int i, j, k;
        int slur = 1;
        char c;
        char *out = malloc(1000 * sizeof(char));

        i = j = k = 0;

        out[j++] = (char)toupper(source[i++]);

        while ((c = source[i++]) != '\0') {
                out[j++] = '-';
                out[j++] = (char)toupper(c);
                for (c = (char)tolower(c), k = 0; k < slur; k++) {
                        out[j++] = c;
                }
                slur++;
        }
        out[j] = '\0';

        return out;
}


Test(ExampleTests, ShouldPassAllTheTestsProvided) {

        {
                const char *source = "ZpglnRxqenU";
                const char *expected = "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu";
                char *actual = accum(source);
                cr_assert_str_eq(expected, actual, "Source: \"%s\" Expected: \"%s\" Actual: \"%s\"", source, expected, actual);
                free(actual); actual = NULL;
        }

        {
                const char *source = "NyffsGeyylB";
                const char *expected = "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb";
                char *actual = accum(source);
                cr_assert_str_eq(expected, actual, "Source: \"%s\" Expected: \"%s\" Actual: \"%s\"", source, expected, actual);
                free(actual); actual = NULL;
        }

        {
                const char *source = "MjtkuBovqrU";
                const char *expected = "M-Jj-Ttt-Kkkk-Uuuuu-Bbbbbb-Ooooooo-Vvvvvvvv-Qqqqqqqqq-Rrrrrrrrrr-Uuuuuuuuuuu";
                char *actual = accum(source);
                cr_assert_str_eq(expected, actual, "Source: \"%s\" Expected: \"%s\" Actual: \"%s\"", source, expected, actual);
                free(actual); actual = NULL;
        }

        {
                const char *source = "EvidjUnokmM";
                const char *expected = "E-Vv-Iii-Dddd-Jjjjj-Uuuuuu-Nnnnnnn-Oooooooo-Kkkkkkkkk-Mmmmmmmmmm-Mmmmmmmmmmm";
                char *actual = accum(source);
                cr_assert_str_eq(expected, actual, "Source: \"%s\" Expected: \"%s\" Actual: \"%s\"", source, expected, actual);
                free(actual); actual = NULL;
        }

        {
                const char *source = "HbideVbxncC";
                const char *expected = "H-Bb-Iii-Dddd-Eeeee-Vvvvvv-Bbbbbbb-Xxxxxxxx-Nnnnnnnnn-Cccccccccc-Ccccccccccc";
                char *actual = accum(source);
                cr_assert_str_eq(expected, actual, "Source: \"%s\" Expected: \"%s\" Actual: \"%s\"", source, expected, actual);
                free(actual); actual = NULL;
        }
}

/*
compare to others:
 - replace the extra '-' at the end with the \0:
   str[i-1] = '\0';
 - do a better job of calculating the final string length and allocate less memory for it
   l = strlen(source); char *out = malloc(l * (l + 1) / 2 + l);  is this correct????
 - use the string's \0 to terminate a loop over the string:
   for (int i = 0; *source; ++i) {}

*/
