#include <stdio.h>
#include <limits.h>
#include <criterion/criterion.h>

#define MAXNC 11

/*
int atoi(const char *);

char *itoa (int value, char * str, int base);

*/

char* pattern(const int n)
{
        int i, j, k, o;
        char c;
        char tmp[MAXNC];
        char *out = malloc((size_t)n * (size_t)n * 2 * sizeof(char));

        for (o = 0, i = 1; i <= n; i++) {
                snprintf(tmp, MAXNC, "%d", i);
                for (j = 0; j < i; j++)
                        for(k = 0; (c = tmp[k]) != '\0'; k++)
                                out[o++] = c;

                out[o++] = '\n';
        }
        out[o - 1] = '\0';
        return out;
}

/*
int main()
{
        char *result = pattern(16);
        printf("%s\n", result);
        return 0;
}
*/


char* TESTPATTERN(const int n){
        int i, j;
        int index = 0;
        char* res;

        if (n < 1)
                return "";

        res = (char*)malloc((n + 3) * n / 2);

        for (i = 1; i <= n; i++) {
                for (j = 0; j < i; j++) {
                        res[index] = (char)('0' + i);
                        index++;
                }

                if (i != n) {
                        res[index] = '\n';
                        index++;
                }
        }

        res[index] = 0;
        return res;
}


Test(pattern, should_pass_all_the_tests_provided) {
        char expected1[] = "1\n22";
        char* actual1 = pattern(2);

        char expected2[] = "1\n22\n333";
        char* actual2 = pattern(3);

        char expected3[] = "1\n22\n333\n4444\n55555\n666666\n7777777\n88888888\n999999999\n10101010101010101010\n1111111111111111111111";
        char* actual3 = pattern(11);

        char expected4[] = "";
        char* actual4 = pattern(0);

        cr_assert_eq(strcmp(expected1, actual1), 0);
        cr_assert_eq(strcmp(expected2, actual2), 0);
        cr_assert_eq(strcmp(expected3, actual3), 0);
        cr_assert_eq(strcmp(expected4, actual4), 0);
}

Test(pattern, randomTests) {
        int i;
        srand(time(0));
        for(i = 0; i < 100; i++)
        {
                int randomInput = rand()%101;

                char* expected = TESTPATTERN(randomInput);
                char* actual = pattern(randomInput);
                cr_assert_eq(strcmp(expected, actual), 0, "expected\n%s\nbut got\n%s\n", expected, actual);
        }
}
