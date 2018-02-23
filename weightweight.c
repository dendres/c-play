#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>


/* join the array of strings */
char *join(char **strings, size_t length, char *separator)
{
        size_t i;
        char *out = malloc(20 * length * sizeof(strings[0]));
        out[0] = '\0'; /* strncat needs a null character to append to ? */

        for (i = 0; i < length; i++) {
                strncat(out, strings[i], strlen(strings[i]));
                if (i < (length - 1)) {
                        strncat(out, separator, 1);
                }
                printf("out = |%s|\n", out);
        }
        return out;
}


/* add together the digits of the given string */
int add_digits(char *s)
{
        int i, total;
        char c;

        for (total = 0, i = 0; (c = s[i]) != '\0'; i++) {
                total += c - '0';
        }
        return total;
}


/* qsort comparison function for "weights" */
int compare_weight(const void *p1, const void *p2)
{
        char *q1 = *(char **)p1; /* XXX wtf? help! */
        char *q2 = *(char **)p2;

        int a = add_digits(q1);
        int b = add_digits(q2);

        if (a == b) {
                return strcmp(q1, q2);
        } else {
                return a - b;
        }
}


char* orderWeight(char* s)
{
        size_t i, token_count, s_len;
        char *token, *copy;
        char **tokens;

        printf("initial = |%s|\n", s);

        /* copy s before tokenizing */
        s_len = strlen(s) + 1;
        copy = malloc(s_len * sizeof(s[0]));
        strncpy(copy, s, s_len);

        /* split copy into tokens */
        tokens = malloc(s_len * sizeof(char*));
        token = strtok(copy, " ");
        for (i = 0; token != NULL; i++) {
                tokens[i] = token;
                token = strtok(NULL, " ");
        }
        token_count = i;

        printf("tokens = ");
        for (i = 0; i < token_count; i++) {
                printf("%s, ", tokens[i]);
        }
        printf("\n");

        qsort(tokens, token_count, sizeof(tokens[0]), compare_weight);

        return join(tokens, token_count, " ");
}


void dotest(char* s, char *expr) {
        char *act = orderWeight(s);
        if(strcmp(act, expr) != 0)
                printf("scale. Error. Expected \n%s\n but got \n%s\n", expr, act);
        cr_assert_str_eq(act, expr, "");
        free(act); act = NULL;
}


Test(orderWeight, ShouldPassAllTheTestsProvided) {
        {
                dotest("103 123 4444 99 2000", "2000 103 123 4444 99");
                dotest("2000 10003 1234000 44444444 9999 11 11 22 123", "11 11 2000 10003 22 123 1234000 44444444 9999");
                dotest("10003 1234000 44444444 9999 2000 123456789", "2000 10003 1234000 44444444 9999 123456789");
                dotest("71899703 200 6 91 425 4 67407 7 96488 6 4 2 7 31064 9 7920 1 34608557 27 72 18 81", "1 2 200 4 4 6 6 7 7 18 27 72 81 9 91 425 31064 7920 67407 96488 34608557 71899703");
                dotest("387087 176 351832 100 430372 8 58052 54 175432 120 269974 147 309754 91 404858 67 271476 164 295747 111 40", "100 111 120 40 8 54 91 164 147 67 176 430372 58052 175432 351832 271476 309754 404858 387087 295747 269974");
                dotest("14593 17221 2346 14749 6248 6100 15518 10195 16896 12132 485 19637 9018 ", "6100 12132 17221 2346 10195 485 9018 15518 6248 14593 14749 19637 16896");

                dotest("8713 12725 8151 12615 5789 14879 3732 4312 1455 8555 12824 ", "4312 12615 1455 3732 8151 12725 12824 8713 8555 14879 5789");

        }
}
