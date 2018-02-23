#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char *strstr(const char *haystack, const char *needle);
*/

char** inArray(char* array1[], int sz1, char* array2[], int sz2, int* lg) {
        /* use a data structure for search and unique list*/

        /* radix trie of patterns
         for each character in text, look for match in trie ?*/


        char **out = malloc((size_t)sz1 * sizeof(char*));
        int i, j, k;
        for (i = 0, k = 0; i < sz1; i++){
                for (j = 0; j < sz2; j++) {
                        if (strstr(array2[j], array1[i]) != NULL) {
                                out[k++] = array1[i];
                        }
                }
        }
        *lg = k;
        return out;
}


int main()
{
        int i;
        int result_size = 0;
        char* arr1[3] = { "arp", "live", "strong" };
        char* arr2[5] = { "lively", "alive", "harp", "sharp", "armstrong" };
        /* dotest(arr1, 3, arr2, 5, "{'arp','live','strong'}"); */

        char **result = inArray(arr1, 3, arr2, 5, &result_size);

        for (i = 0; i < result_size; i++){
                printf("%s, ", result[i]);
        }
        printf("\n");

        return 0;
}
