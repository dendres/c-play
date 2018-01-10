#include <stdio.h>
#include <ctype.h>

/*
K&R Exercise 3-3

expand series notation in strings: a-z
*/
void expand(char s1[], char s2[])
{
        int i, j, k;
        char c, first, last; /* the first and last characters in the expansion */

        i = j = 0;
        s2[j++] = s1[i++]; /* always skip the first character */

        while (first = s1[i - 1], c = s1[i], c != '\0') {
                last  = s1[i + 1];

                if (c == '-' && isalnum(first) && isalnum(last) && first <= last) {
                        /* in order to handle a-a, overwrite first and last*/
                        j--; /* backup to overwrite first */
                        /* write the whole sequence */
                        for(k = (int)first; k <= (int)last; k++) {
                                s2[j++] = (char)k;
                        }
                        j--; /* backup to overwrite last */
                } else {
                        s2[j++] = s1[i];
                }
                i++;
        }
        s2[j] = '\0'; /* mark the end of the new string */
}


int main()
{
        char s1[] = "-a a-f -a-g -a a- a-- --a a-b-c z-a g-l-p a-z0-9 A-D Z-a a-a b-a a-";
        char s2[1000];

        printf("%s\n", s1);

        expand(s1,s2);
        printf("%s\n", s2);
        return 0;
}


/*
compare to others:
 - need to handle \t in addition to ' ' when detecting whitespace
 - instead of checking if first and last are - or ' '
   ... would be better to check if first and last are a-zA-Z0-9
 - use ctype.h isalnum to test for a-zA-Z0-9

*/
