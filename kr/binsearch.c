#include <stdio.h>


/*
K&R Page 58
find x in a sorted array v[] using binary search
*/
int binsearch(int x, int v[], int n)
{
        int low, high, mid = 0;

        high = n - 1;
        while (low <= high) {
                mid = (low + high) / 2;

                if (x < v[mid])
                        high  = mid -1;
                else if (x > v[mid])
                        low = mid + 1;
                else
                        return mid;
        }

        return -1;
}


/*
K&R Exercise 3-1
rewrite binsearch with one test inside the loop

I gave up and looked for answers:
 - everyone moves a test inside the while condition
   this is NOT moving it "outside" the loop
   ... so I think this question is BS.
   XXX revisiting later!
*/
int binsearch2(int x, int v[], int n)
{
        int low, high, mid = 0;

        high = n - 1;
        while (low <= high) {
                mid = (low + high) / 2;

                if (x < v[mid])
                        high  = mid -1;
                else if (x > v[mid])
                        low = mid + 1;
                else
                        return mid;
        }

        return -1;
}


int main(){

        int v[11];
        int n = sizeof(v)/sizeof(v[0]);
        int x = 19;
        int i = 0;
        int result  = 0;

        printf("array to search = ");
        for (i = 0; i < n; i++) {
                v[i] = i + 10;
                printf("%d ", v[i]);
        }
        printf("\n");

        result = binsearch(x, v, n);
        printf("result = %d\n", result);


        /* compare performance of binsearch and binsearch2 */

        return 0;
}
