#include <stdio.h>

/*
K&R Exercise 2-5

any(s1,s2):
 - is any character from s2 found in s1?
   if so, return the location in s1 of the first occurance
   if not, return -1

*/


int any(char s1[], char s2[]) {
        int i, j;

        for (i = 0; s1[i] != '\0'; i++) {
                for (j = 0; s1[j] != '\0'; j++) {
                        if (s1[i] == s2[j]) {
                                return i;
                        }
                }
        }
        return -1;
}


int main() {
        char s1[] = "hello there o";
        char s2[] = "not many";

        printf("%d\n", any(s1,s2));
        return 0;
}

/*
that was too easy... I must be missing something. 

*/
