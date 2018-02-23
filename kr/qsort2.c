#include <stdio.h>
#include <stdlib.h>


/*
K&R page 121
swap i and j in v
v can be a list of anything
*/
void swap(void *v[], int i, int j)
{
        void *temp;

        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
}


/*
K&R Page 106
*/
int strcmp(char *s, char *t)
{
        int i;

        for (i = 0; s[i] == t[i]; i++)
                if (s[i] == '\0')
                        return 0;

        return s[i] - t[i];
}


/*
K&R page 121

compare s1 and s2 numerically
*/
int numcmp(char *s1, char *s2)
{
        double v1, v2;

        v1 = atof(s1);
        v2 = atof(s2);

        if (v1 < v2)
                return -1;
        else if (v1 > v2)
                return 1;
        else
                return 0;
}


/* K&R page 120

qsort that takes a function pointer for the comparison

*/
void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
        int i, last;

        if (left >= right)
                return;

        swap(v, left, (left + right) / 2);

        last = left;
        for (i = left + 1; i <= right; i++)
                if ((*comp)(v[i], v[left]) < 0)
                        swap(v, ++last, i);

        swap(v, left, last);
        qsort(v, left, last - 1, comp);
        qsort(v, last + 1, right, comp);
}
