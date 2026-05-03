#include <stdio.h>
#include <stdlib.h>

static inline float kahan_sum(int val);
static inline float kahan_sum_add_error(int val);  /* Kahan sum, using "+" to remedy/compensate corrective values */
static inline float kahan_mult(int val);

int main(void)
{
    float sum;
    int val;
    // Kahan sum experiments
    val = 10000;
    printf("Regular Kahan summation algorithm from 1 to %d\n", val);
    sum = kahan_sum(val);
    printf("sum = %d  (as int), %.3f (as float)\n", (int)sum, sum);

    printf("Kahan sum: using \"+\" to re-apply errors back to running sum. Range: 1 to %d\n", val);
    sum = kahan_sum_add_error(val);
    printf("sum = %d  (as int), %.3f (as float)\n", (int)sum, sum);

    // Kahan product experiment
    val = 25;
    printf("Kahan Product: applying Kahan's algorithm to running product from 1 to %d\n", val);
    sum = kahan_mult(val);
    printf("sum = %d  (as int), %.3f (as float)\n", (int)sum, sum);

    val = 50;
    printf("Kahan Product: applying Kahan's algorithm to running product from 1 to %d\n", val);
    sum = kahan_mult(val);
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

static inline float kahan_sum(int val)
{
    /* Addition introduces round-off error: the larger a value, the wider its bit-representation
     *  - Subtraction recovers the lower-bits that are rounded off. 
     *  - Another way to "memorize"/"understand" this: `corr` is actually the error generated from
     *  rounding, to have error-free final sum, it has to be *subtracted* from the addend.
     * */
    float sum = 0.0f;
    float corr = 0.0f;
    for (int i = 1; i <= val; i++) {
        float x = (float)i;     /* Addend (加數) of this iteration */
        float y = x - corr;     /* Addend minus rounding error (from last iteration) */
        float t = sum + y;      /* lower bits (of y) might be rounded off */
        corr = (t - sum) - y;   /* recovering rounding error (the lower bits
                                   that might be rounded off) */
        sum = t;
    }
    return sum;
}

static inline float kahan_sum_add_error(int val)
{
    /* Kahan sum, using "+" to remedy/compensate rounding errors on addend */
    float sum = 0.0f;
    float error = 0.0f;
    for (int i = 1; i <= val; i++) {
        float x = (float)i;
        float y = x + error;    // re-applying error to running sum with "+" (counter-intuitive)
        float t = sum + y;
        error = (t - sum) - y;
        sum = t;
    }
    return sum;
}

static inline float kahan_mult(int val)
{
    /* Applying kahan's algorithm when multiplying from 1 to 1000
     *  @return product: the "running product" from 1 to 1000
     *
     *  ??Is this the correct way of doing this? Hesistant because of the division.
     *      - Also, seems like the error re-application step will frequently be non-zero since
     *      multiplication grows a lot faster than addition.
     */
    float product = 1.0f;
    float corr = 0.0;
    for (int i = 1; i <= val; i++) {
        float x = (float)i;         // multiplicand of this round
        float y = x - corr;         // apply error/correction to multiplicand
        float t = product * y;
        
        corr = (t / product) - y;   // acutal multiplicand of this round - expeced multiplicand
        product = t;
    }
    return product;
}
