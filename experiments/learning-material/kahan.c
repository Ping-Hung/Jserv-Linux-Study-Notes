#include <stdio.h>
#include <stdlib.h>

static inline float regular_sum();
static inline float kahan_sum();
static inline float kahan_sum_add_error();

int main(void)
{
    float sum;

    printf("regular summation from 1 to 10000\n"
           "expecting 50005000\n");
    sum = regular_sum();
    printf("sum = %d  (as int), %.3f (as float)\n", (int)sum, sum);

    printf("Regular Kahan summation algorithm from 1 to 10000\n");
    sum = kahan_sum();
    printf("sum = %d  (as int), %.3f (as float)\n", (int)sum, sum);

    printf("Kahan sum: using \"+\" to re-apply errors back to running sum from 1 to 10000\n");
    sum = kahan_sum_add_error();
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
    /* Addition introduces round-off error: the larger a value, the wider its bit-representation
     *  - Subtraction somehow recovers the lower-bits that are rounded off. 
     *  - Another way to "memorize"/"understand" this: `corr` is actually the error generated from
     *  rounding, to have error-free final sum, it has to be *subtracted* from the addend.
     * */
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

static inline float kahan_sum_add_error()
{
    float sum = 0.0f;
    float error = 0.0f;
    for (int i = 0; i <= 10000; i++) {
        float x = (float)i;
        float y = x + error;    // re-applying error to running sum with "+" (counter-intuitive)
        float t = sum + y;
        error = (t - sum) - y;
        sum = t;
    }
    return sum;
}
