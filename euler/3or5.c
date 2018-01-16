#include <stdio.h>
#include <criterion/criterion.h>


/*
https://projecteuler.net/problem=1

sum of multiples of 3 or 5 less than number
3+5+6+9+10+12+15+18+20

*/
int solution(int number) {
        int i, t;
        for (i = 0, t = 0; i < number; i++)
                if (i % 3 == 0 || i % 5 == 0 )
                        t += i;
        return t;
}


/*
  https://en.wikipedia.org/wiki/Arithmetic_progression#Sum

  to see how to sum an arithmetic series,
  rerverse the sequence and add it to itself term by term

  3  + 6  + 9  + 12 + 15 = 45
  15 + 12 + 9  + 6  + 3  = 45
  ---------------------------
  18 + 18 + 18 + 18 + 18 = 90

  18 * 5 = 90
  18 * 5 / 2 = 45
  (3 + 15) * 5 / 2 = 40
  (first_element + last_element) * number_of_terms / 2 = sum


  Now find the arithmetic sum of multiples of M less than L":

  number_of_terms = (L - 1) / M
  first_element = M
  last_element = ((L - 1) / M) * M
*/
int as_sum(int m, int l)
{
        int n = (l - 1) / m;
        int a = m;
        int b = ((l - 1) / m) * m;

        printf("n = %d, a = %d, b = %d\n", n, a, b);

        return (a + b) * n / 2;
}


/*
sum of the 3 series + sum of the 5 series - sum of the 15 series
subtract the sum of the 15 series to avoid double counting
numbers that are multiples of both 3 and 5

  10: 18 + 5 + 0 = 23
  16: 45 + 30 - 15 = 60
  22: 63 + 50 - 15 = 98

*/
int s2(int n)
{
        int a = as_sum(3, n);
        int b = as_sum(5, n);
        int c = as_sum(15, n);

        printf("a = %d, b = %d, c = %d\n", a, b, c);

        return a + b - c;
}


Test(the_multiply_function, should_pass_all_the_tests_provided) {
        int x;
        cr_assert_eq(x = solution(10), 23, "expected 23, but got %d", x);
        cr_assert_eq(x = solution(16), 60, "expected 60, but got %d", x);
        cr_assert_eq(x = solution(1000), 233168, "expected 233168, but got %d", x);

        cr_assert_eq(x = s2(10), 23, "2 expected 23, but got %d", x);
        cr_assert_eq(x = s2(16), 60, "2 expected 60, but got %d", x);
        cr_assert_eq(x = s2(1000), 233168, "2 expected 233168, but got %d", x);
}
