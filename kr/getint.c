#include <stdio.h>
#include <ctype.h>


#define BUFSIZE 1000

char buf[BUFSIZE];
int bufp = 0;

/* getch and ungetch from K&R page 79*/
char getch(void)
{
        return (bufp > 0) ? buf[--bufp] : (char)getchar();
}


void ungetch(char c)
{
        if (bufp >= BUFSIZE) {
                printf("ungetch: too many characters\n");
        } else {
                buf[bufp++] = c;
        }
}

/* getint from K&R page 97 */
int getint(int *pn)
{
        char c;
        int sign;

        while (isspace(c = getch()))
                ;

        if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetch(c);
                return 0;
        }

        sign = (c == '-') ? -1 : 1;

        if (c == '+' || c == '-') {
                c = getch();
                /* K&R Exercise 5-1: + or - not followed by a digit is not a valid int */
                if (!isdigit(c)) {
                        /* push back the sign instead of the last non-digit??
                           others do  ungetch(sign == 1 ? '+' : '-')
                           ... but this lets a '-' by itself impact the next valid int
                           ... which I don't think it should do:
                           '-asdf5' or '-  5' should both == '5', NOT '-5'
                           ... so I am going to ungetch the last invalid character
                           and not mess with sign
                         */
                        ungetch(c);
                        return 0;
                }
        }

        for (*pn = 0; isdigit(c); c = getch())
                *pn = 10 * *pn + (c - '0');

        *pn *= sign;

        if (c != EOF)
                ungetch(c);

        return c;
}


int main()
{
        int i, x, l, array[100];

        /*gather valid integers and set them in array*/
        for (x = 0, i = 0; i < 100 && (x = getint(&array[i])) != EOF; i++) {
                if (x == 0)
                        i--;
        }

        /* print the valid integers from array*/
        for (l = i, i = 0; i < l; i++) {
                printf("|%d| ", array[i]);
        }
        printf("\n");

        return 0;
}


/*
compare to others:
 - do you push back the space, or the +-?
   ... looks like everyone else is pushing back the +-


*/
