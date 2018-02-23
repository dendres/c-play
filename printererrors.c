#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>

char *printerError(char *s)
{
        int i, errors;
        char c, *out = malloc(9 * sizeof(char));

        for (errors = 0, i = 0; (c = s[i]) != '\0'; i++)
                if (c < 'a' || c > 'm')
                        errors++;

        sprintf(out, "%d/%d", errors,i);
        return out;
}

/*
int main()
{
        char *act = printerError("hello");
        printf("%s", act);
        return 0;
}
*/



void dotest(char *s, char *exp)
{

        char *act = printerError(s);
        if(strcmp(act, exp) != 0)
                printf("Error. Expected %s but got %s\n", exp, act);
        cr_assert_str_eq(act, exp, "");
        free(act); act = NULL;
}


Test(printerError, ShouldPassAllTheTestsProvided)
{
        char* s = "aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyz";
        dotest(s, "3/56");
        s = "kkkwwwaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyz";
        dotest(s, "6/60");
        s = "kkkwwwaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyzuuuuu";
        dotest(s, "11/65");
}

/*
asprintf allocates memory for the string!!!
 but requires #define _GNU_SOURCE  and is not portable!

*/
