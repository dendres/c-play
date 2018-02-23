#include <stdio.h>

int main()
{
        char *pmessage = "now is the time";

        printf("%s\n", pmessage);
        pmessage[3] = 'X';
        printf("%s\n", pmessage);

        return 0;
}
