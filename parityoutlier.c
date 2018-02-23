#include <stdlib.h>
#include <criterion/criterion.h>

int find_outlier(const int *values, size_t count)
{
        size_t i;
        int evens, odds, last_even, last_odd;

        if (count < 3)
                return -1;

        for (evens = 0, odds = 0, i = 0; i < count; i++) {
                if (values[i] % 2 == 0) {
                        last_even = values[i];
                        evens++;
                } else {
                        last_odd = values[i];
                        odds++;
                }
        }

        if (evens > odds)
                return last_odd;
        else
                return last_even;

}

/*
compare to others:
 - you have to traverse the whole thing anyway:
   so save the last odd and last even
   and keep a count of evens and odds

*/



Test(ExampleTests, ShouldPassAllTheTestsProvided)
{
        {
                int values[] = { 2,6,8,10,3 }; /* odd at the back */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = 3;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }

        {
                int values[] = { 2,6,8,200,700,1,84,10,4 }; /* odd in the middle */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = 1;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }

        {
                int values[] = { 17,6,8,10,6,12,24,36 }; /* odd in the front */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = 17;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }

        {
                int values[] = { 2,1,7,17,19,211,7 }; /* even in the front */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = 2;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }

        {
                int values[] = { 1,1,1,1,1,44,7,7,7,7,7,7,7,7 }; /* even in the middle */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = 44;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }

        {
                int values[] = { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,35,5,5,5,5,5,5,5,5,5,5,7,7,7,7,1000 }; /* even at the end */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = 1000;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }

        {
                int values[] = { 2,-6,8,-10,-3 }; /* odd at the back, negative */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = -3;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }

        {
                int values[] = { 2,6,8,2,-66,34,-35,66,700,1002,-84,10,4 }; /* odd in the middle, negative */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = -35;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }

        {
                int values[] = { -20,1,7,17,19,211,7 }; /* even in the front, negative */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = -20;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }

        {
                int values[] = { 1,1,-1,1,1,-44,7,7,7,7,7,7,7,7 }; /* even in the middle, negative */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = -44;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }

        {
                int values[] = { 1,0,0 }; /* odd answer, zeroes */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = 1;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }

        {
                int values[] = { 3,7,-99,81,90211,0,7 }; /* even in the middle, zero */
                size_t count = sizeof(values)/sizeof(values[0]);
                int expected = 0;
                int received = find_outlier(values, count);
                cr_assert_eq(expected, received, "Expected: %d. Received: %d.", expected, received);
        }
}
