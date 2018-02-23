# include <stdio.h>
# include <math.h>
# include <stdlib.h>

/*
golden ratio


1.6180339887498948482045868343656381177203091798057628621
1.6180339887498948482045868343656381

13, 21, 34, 55, 89, 144,

dottest(15, "3, 5, 1")
dottest(40, "5, 8, 1")
dottest(104, "8, 13, 1")
dottest(273, "13, 21, 1")
dottest(714, "21, 34, 1");
dottest(800) "34, 55, 0"); xxxx
dottest(1870, "34, 55, 1")
dotest(4895, "55, 89, 1");
dotest(5895, "89, 144, 0"); xxxx
dotest(12816, "89, 144, 1");
dottest(33552, "144, 233, 1")
dottest(87841, "233, 377, 1")
dottest(229970, "377, 610, 1")
dottest(447577, "610, 987, 0") xxx
dottest(602070, "610, 987, 1")
dottest(1576239, "987, 1597, 1")
dottest(4126648, "1597, 2584, 1")
dottest(10803704, "2584, 4181, 1")
dottest(28284465, "4181, 6765, 1")
dotest(74049690, "6765, 10946, 1");
dottest(193864606, "10946, 17711, 1")
dottest(507544127, "17711, 28657, 1")
dottest(1328767776, "28657, 46368, 1")
dottest(3478759200, "46368, 75025, 1")


447577 610, 987, 0  ... but got 987, 1597, 0


productFib(800) # should return {34, 55, false}
                # since F(8) = 21, F(9) = 34, F(10) = 55 and 21 * 34 < 800 < 34 * 55


800, 22, 36, 8
... needs to calculate:
     34, 55

5895, 60, 98, 15
... needs to calculate:
      89, 144


        for(i = 0; i < 21; i++) {
                x = t[i] / 1.6180339887498;
                n = round(sqrt(x));
                m = t[i] / n;
                printf("%f, %f, %f\n", t[i], n, m);
        }

*/
typedef unsigned long long ull;

ull* productFib(ull prod) {

        ull *out = malloc(3 * sizeof(ull*));
        ull isfib = 1;
        long double golden = 1.6180339887498948482;
        long double srfive = 2.2360679774997896964;
        long double p = (long double)prod;
        long double n, m, r, t;

        n = roundl(sqrtl(p / golden));
        m = p / n;
        r = fmodl(p, n);

        if (r > 0) {
                isfib = 0;
                t = floorl(logl(n * srfive) / logl(golden)) + 1;
                n = roundl(powl(golden, t) / srfive);
                m = roundl(powl(golden, t + 1) / srfive);
        }

        out[0] = (ull)n;
        out[1] = (ull)m;
        out[2] = isfib;
        return out;
}

int main()
{
        ull t[22] = {15, 40, 104, 273, 714,
                        800, 4895, 5895, 33552, 87841,
                     229970, 447577, 602070, 1576239, 4126648, 10803704,
                        28284465, 74049690, 193864606, 507544127, 1328767776,
                        3478759200};
        ull *out;
        int i;

        for(i = 0; i < 21; i++) {
                out = productFib(t[i]);
                printf("%d, %d, %d, %d\n", t[i], out[0], out[1], out[2]);
        }

        return 0;
}





