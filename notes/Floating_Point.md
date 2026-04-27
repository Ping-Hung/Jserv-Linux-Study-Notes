# IEEE754 Format
Float32:
```
 31  30        23 22                              0
┌────┬──────────┬──────────────────────────────────┐
│ S  │ Exponent │            Mantissa              │
└────┴──────────┴──────────────────────────────────┘
  1b     8b                   23b
```
* For convenience, **values stored at these fields** are denoted $s$, $E$, and $M$.
* (Actual, numeric) value and format conversion formula
```math
    \text{value} = (-1)^s \times (1.M) \times 2^{E - 127}
```
## Notes on Mantissa
* This is directly related to precision of the value that's represented by this format, wider
  Mantissa field → better precision
* The $1$ shown in the formula is not stored, only appears in value conversion, it's called the
  <mark>**hidden bit**</mark>.

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

# Problem: Sequentially Summing up Floating Point Values Yields Error
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

