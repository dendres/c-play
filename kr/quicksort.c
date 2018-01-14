#include <stdio.h>
#include <string.h>

#define MAXLINELENGTH 1000
#define MAXLINECOUNT 100


/*K&R page 69*/
int get_line(char s[], int lim)
{
        char c;
        int i = 0;

        while (--lim > 0 && (c = (char)getchar()) != EOF && c != '\n')
                s[i++] = c;

        if (c == '\n')
                s[i++] = c;

        s[i] = '\0';

        return i;
}


/*
K&R 5-7

read all the lines of input
sort them
print them back out

readlines should store lines in an array supplied by main
... instead of using "alloc"

storage : a character array where all the lines will be stored
lines: an array of pointers to the start of each line in storage

XXX prints garbage if MAXLINECOUNT < 3 ???????
    but works fine for 3 and above

read_lines:
 - overwrites storage and lines
 - returns the number of lines read from stdin
*/
int read_lines(char storage[], char *lines[]){

        int i, line_length;

        lines[0] = storage;
        i = 0;
        while((line_length = get_line(lines[i], MAXLINELENGTH)) > 0 ) {
                if (i >= MAXLINECOUNT)
                        return i;

                lines[i+1] = lines[i] + line_length + 1;
                i++;
        }

        return i;
}


void write_lines(char *lineptr[], int nlines)
{
        int i;
        for (i = 0; i < nlines; i++)
                printf("%s", lineptr[i]);
}


void swap(char *v[], int i, int j) {
        char *temp;

        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
}


void qsort(char *v[], int left, int right)
{
        int i, last;

        if (left >= right)
                return;

        swap(v, left, (left + right) / 2);

        last = left;
        for (i = left +1; i <= right; i++)
                if (strcmp(v[i], v[left]) < 0 )
                        swap(v, ++last, i);

        swap(v, left, last);
        qsort(v, left, last - 1);
        qsort(v, last + 1, right);
}

int main()
{
        int line_count;
        char storage[MAXLINELENGTH * MAXLINECOUNT];
        char* lines[MAXLINECOUNT]; /* a list of pointers to locations in storage[] */

        line_count = read_lines(storage, lines);
        qsort(lines, 0, line_count);
        write_lines(lines, line_count);
        return 0;
}


/*
compare to others:
 - if an extra spot is allocated, overwrite it with \0 if possible

*/
