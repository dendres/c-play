#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>




/*
  return an array of size_t
  parsed from the given string
  modify return_length to match
*/
size_t *parse_size_t(char *s, size_t *return_length)
{
        size_t *out = malloc(sizeof(s));
        size_t i, j, x;
        char c, last;

        i = j = x = 0;
        do {
                c = s[i];
                if (isdigit(c)) {
                        x = x * 10 + (size_t)(s[i] - '0');
                } else if (isdigit(last)) {
                        out[j++] = x;
                        x = 0;
                }
                last = c;
                i++;
        } while (c != '\0');

        *return_length = j;

        return out;
}


int main()
{
        char *s = "   578   895  ;sfe 333  4 9 88888   ";
        /* char *s = ""; */
        size_t i, len;

        size_t *out = parse_size_t(s, &len);

        printf("out = ");
        for (i = 0; i < len; i++) {
                printf("%lu,", out[i]);
        }
        printf("\n");

        return 0;
}
