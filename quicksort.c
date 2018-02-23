#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int comp(const void *p1, const void *p2)
{
        return strcmp(* (char * const *) p1, * (char * const *) p2);
}


int main()
{
        char buf[] = "103 123 4444 99 2000";
        size_t i, j, token_count;
        char *token;
        char **tokens = malloc(10 * sizeof(char*));

        for (i = 0, token = strtok(buf, " "); token != NULL; i++) {
                tokens[i] = token;
                token = strtok(NULL, " ");
        }
        token_count = i;


        for (j = 0; j < token_count; j++) {
                printf("%s, ", tokens[j]);
        }
        printf("\n");

        /* qsort(an array, of this many elements, where each element is this size, and a comparator) */
        qsort(tokens, token_count, sizeof(tokens[0]), comp);

        for (j = 0; j < token_count; j++) {
                printf("%s, ", tokens[j]);
        }
        printf("\n");

        free(tokens); tokens = NULL;

        return 0;
}
