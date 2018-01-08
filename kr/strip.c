#include <stdio.h>
#include <stdbool.h>

/*
K&R Exercise 2-4
modify squeeze to delete each character in s1 that matches any character in s2
*/

void squeeze(char s[], int c) {
        int i, j;

        for (i = j = 0; s[i] != '\0'; i++)
                if (s[i ] != c)
                        s[j++] = s[i];
        s[j] = '\0';
}

void strip(char s1[], char s2[]) {
        int i, j, k;
        bool found;

        for (i = j = 0; s1[i] != '\0'; i++) {
                for (found = false, k = 0; s2[k] != '\0'; k++)
                        if (s1[i] == s2[k])
                                found = true;
                if (!found)
                        s1[j++] = s1[i];
        }
        s1[j] = '\0';
}


int main(){
        char s1[] = "helloehlhlelhhhleeelo";
        char s2[] = "he";

        strip(s1, s2);

        printf("%s\n", s1);
        return 0;
}

