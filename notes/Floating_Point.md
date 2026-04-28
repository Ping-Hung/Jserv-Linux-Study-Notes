# IEEE754 Format
Float32:
* A 32-bit storage space for values with a decimal dot (.), it's supposed to represent real numbers.
```
 31  30        23 22                              0
┌────┬──────────┬──────────────────────────────────┐
│ S  │ Exponent │            Mantissa              │
└────┴──────────┴──────────────────────────────────┘
  1b     8b                   23b
```
* For convenience, **values stored at these fields** are denoted $s$, $E$, and $M$.
* Each one of these fields could be regarded as signed integer when isolated out for further
  disucssion.
    * At the lowest level, they are simply binary patterns, the interpretation depends on context.
* (Actual, numeric) value and format conversion formula
```math
    \text{value} = (-1)^s \times (1.M) \times 2^{E - 127}
```
## Notes on Mantissa
* This is directly related to the precision of the value that's represented by this format, wider
  Mantissa field → better precision
* The $1$ shown in the formula is not stored, and only appears in value conversion, it's called the
  <mark>**hidden bit**</mark>.
* The storage field *Mantissa* is **23-bits** wide. However, it has a value range equivalent to that
  of a **24-bit** number due to the existence of the **hidden-bit** which isn't stored physically.

## Reason for the bias (127)
* **Main Reason**: IEEE-754 reserves `0x00` and `0xff` at Exponent field for subnormal and NaN
  values.
### Conversion Formula
```math
    \text{E} = \text{Exponent} + 127 \iff \text{Exponent} = \text{E} - 127
```
### Proof
Know that the actual binary-exponent value ranges from -127 to 128 becuase it is an 8-bit signed
integer. Formally,
```math
\text{Exponent} \in [-128, 127] \subset \mathbb{N}.
```
Adding 127 to $\text{Exponent}$ yeilds
```math
\text{Exponent} + 127 \in [-1, 254] \subset \mathbb{N}.
```
IEEE754 reserves `0x00` (value $0$) and `0xff` (value $-1$ for signed number) for subnormal and NaN
values, so the actual range of $\text{E}$ is $[1, 254]$

# Problem: Running Sum of Floating Point Values Yields Error Stemming from Rounding.
Example Program:
```c
#include <stdio.h>

int main(void) 
{
    float sum = 0.0f;
    for (int i = 0; i < 10000; ++i) {
        sum += i + 1;
    }
    printf("Sum: %f\n", sum);
}
```
## Root Causes
* Mantissa of FP32 is a finite 23-bit field, (valid, accurate, error-free) value range is $[0, 2^{24}]$.


# Kahan Summation
* book-keeping the lower-bit errors arised from summation 
* attempting to add it back in the next iteration.
```c
float sum  = 0.0f;
float corr = 0.0f;  /* corrective value for rounding error */

for (int i = 0; i < 10000; ++i) {
    float x = (float)(i + 1);  /* current addend */
    float y = x - corr;        /* apply correction value to current addend */
    float t = sum + y;         /* low bits may be rounded away */
    corr = (t - sum) - y;      /* recover lost bits and store it in corr */
    sum  = t;
}
```

* Addition triggers round-off: the larger the running sum, the more bits it takes up.
* `t = sum + y`: since `sum` might be a lot bigger than `y`, `sum + y` can trigger round-off.
* `corr = (t - sum) - y`: 
    * `(t - sum)`: the ***actual value*** that *is added* in this iteration, it is expected to be `y` when
      there's no round-off.
    * `y`: the ***expected value*** that *should be added* in this iteration.
    * Difference of the 2 can be viewed as the *"rounding error"*: ***actual value - expected value***.

## Core Theme(s)
* Accurately capture/book-keep the *rounding error* appeared in each iteration, and
* Adjust the final running sum accordingly by modifying the addend.
    * The key is *adjust the running sum*, so `float y = x - corr` can actually be swapped with
      `float y = x + corr`, since both (re-)applies rounding error back to the final sum.
        * Only difference is that "subtracting" error is much more intuitive.
