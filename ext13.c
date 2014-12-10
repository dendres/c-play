
#include <stdio.h>

int main(int argc, char *argv[])
{

        int i = 0;
        int j = 0;
        char *arg = "hi";
        char letter;

        for(i = 1; i < argc; i++) {
                arg = argv[i];
                for(j = 0; letter = arg[j], letter != '\0'; j++) {

                        switch(letter) {
                        case 'a':
                        case 'A':
                                printf("%d: 'A'\n", i);
                        break;
                        case 'e':
                        case 'E':
                                printf("%d: 'E'\n", i);
                        break;
                        default:
                                printf("%d: %c is not a vowel\n", i, letter);
                        }
                }
        }
        return 0;
}
