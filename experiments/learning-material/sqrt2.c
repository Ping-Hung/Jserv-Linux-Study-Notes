#include <stdio.h>
#include <stdlib.h>

#define MIN_INT 1 << 31
#define MAX_INT (1 << 31) - 1

int newton(int n); /* finds integer approximation to √n ⇔  floor(√n) */

int main(void)
{
}

int newton(int n)
{
    if (n < 0) {
        printf("error: square-root of negative number %d is undefined\n", n);
        return MIN_INT;
    }
    if (n < 4) return 1;

    unsigned int ans = n / 2;   /* suppose ans = √n ⇔  ans^2 = n. When n ≥ 2,
                                   ans^2 ≥ 2*n always holds, which is a valid
                                   initial condition. Also, dividing by 2
                                   (unsinged, equals to >>= 1) prevents
                                   overflow (of 32-bit unsigned)*/

    if (ans > 65535) {  // 65535 = 2^16 - 1: prevent overflow of 16-bit values
                        // (C-standards requires int to have min. of 16-bit
                        // storage 
        ans = 65535;
    }
    
    while (ans * ans > n) { /* line 21 establishes ans ≥ √n, since we are
                               finding floor(√n), loop exits when ans^2 ≤ n */
        ans = (ans + n / ans) / 2;
    }
    return ans;
}
