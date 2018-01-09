#include <stdio.h>
#include <string.h>

/*
K&R Exercise 3-3

expand series notation in strings: a-z

handle cases: -a-z -a a- a-b-c  a-- --a

*/
void expand(char s1[], char s2[])
{
        int i, j, k, first, last, s1_length;
        int int_dash = (int)'-';
        int int_space = (int)' ';
        s1_length = (int)strlen(s1);

        for (i = 0, j = 0; i < s1_length; i++, j++) {
                if (i > 0 && s1[i] == '-') {
                        first = (int)s1[i-1];
                        last = (int)s1[i+1];

                        if (last > first && first != int_dash && last != int_dash && first != int_space && last != int_space) {
                                j--;
                                for(k = first; k <= last; k++, j++) {
                                        s2[j] = (char)k;
                                }
                                j = j - 2;
                        } else {
                                s2[j] = s1[i];
                        }
                } else {
                        s2[j] = s1[i];
                }
        }
        s2[j] = '\0';
}


int main()
{
        char s1[] = "-a a-f -a-g -a a- a-- --a a-b-c z-a g-l-p a-z0-9 Z-a a-";
        char s2[1000];

        printf("%s\n", s1);

        expand(s1,s2);
        printf("%s\n", s2);
        return 0;
}
