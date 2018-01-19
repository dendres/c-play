#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
  parse_numbers returns an array of strings of numbers
  parsed from the given string.
  It modifies return_length to match.
  Long numbers are split.
*/
char **parse_numbers(char *s, size_t *return_length)
{
        char **out = malloc((1 + strlen(s) / 2)  * sizeof(char*));
        size_t i, j, k, max_sdc;
        char c, last;

        i = j = k = 0;
        max_sdc = 20; /*size of string of digit characters + \0 */
        out[j] = malloc(max_sdc * sizeof(char*));

        do {
                if (k < max_sdc) /* no delimiter for split numbers */
                        c = s[i++];
                if (isdigit(c) && k < max_sdc) {
                        out[j][k++] = c;
                } else if (isdigit(last)) {
                        out[j][k] = '\0';
                        k = 0;
                        out[++j] = malloc(max_sdc * sizeof(char));
                }
                last = c;
        } while (c != '\0');

        *return_length = j;
        return out;
}



int main()
{
        /* char s[] = "   578   895  ;sfe 333  4 9 88888   "; */
        /* char s[] = " 1 012345678901234567890123456 1"; */
        char *s = "0 1 2 3 4 5 6 7 8";
        size_t i, len;

        char **out = parse_numbers(s, &len);

        printf("out = ");
        for (i = 0; i < len; i++) {
                printf("%s,", out[i]);
        }
        printf("\n");

        return 0;
}
