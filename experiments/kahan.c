#include <stdio.h>
#include <stdlib.h>

static inline float regular_sum();
static inline float kahan_sum();

int main(void)
{
    printf("regular summation from 1 to 10000\n"
           "expecting 50005000\n");
    float sum = regular_sum();
    printf("sum = %d  (as int), %.3f (as float)\n", (int)sum, sum);

    printf("Kahan summation algorithm from 1 to 10000\n");
    sum = kahan_sum();
    printf("sum = %d  (as int), %.3f (as float)\n", (int)sum, sum);
    return EXIT_SUCCESS;
}

static inline float regular_sum()
{
    float sum = 0.0f;
    for (int i = 0; i < 10000; i++) {
        sum += i + 1;   /* Addition introduces round-off error */
    }
    return sum;
}

static inline float kahan_sum()
{
    /* Addition causese round-off error (ignoring lower bits), so use minus to
     * put them back ?*/
    float sum = 0.0f;
    float corr = 0.0f;
    for (int i = 1; i <= 10000; i++) {
        float x = (float)i;     /* Addend (加數) of this iteration */
        float y = x - corr;     /* Addend minus rounding error (from last iteration) */
        float t = sum + y;      /* lower bits (of y) might be rounded off */
        corr = (t - sum) - y;   /* recovering rounding error (the lower bits
                                   that might be rounded off) */
        sum = t;
    }
    return sum;
}
