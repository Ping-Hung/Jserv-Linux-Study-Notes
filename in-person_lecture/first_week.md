Date: 2/24/2026  
# IEEE-754 and Kahan's Algorithm
* [初步解讀浮點數](https://hackmd.io/@sysprog/B1dc2oq_Wx)
    - IEEE-754 floating point format
    - Statistics concepts
    - Discrete system
| |`float`|`double`|
|:---:|:---:|:---:|
|Mantissa| 23-bits| 53-bits|
|Exponents| 8-bits| 11-bits|

- Error in algorithm arises from manipulation/bit-propagation from mantissa to exponent
    - `corr`: the corrective term for rounding error
    - if adding introduces rounding error, accumulate them in `corr` and
      subtract them from sum

## ULP: units of least precison
- Not all nubmers could be represented by 24-bits (single precison `float`)
    - if MSB is 23+ bits away form LSB, lower bits get rounded off

**Discrete Systems**
- limited "width" for representation
- "Infinity" is non-existent
- Rounding error arouse when trying to represent (possibly infinite) value with
  finite "bits/fields"


# 期初考
1. Right shift to replace division. Right shifts drop lower bits, which
   accumulates error. What should 甲 be?
```c
u64 sum = 0;
u64 remainder = 0; /* Kahan style correction carry bits truncated */
for (int i =  0; i < 1000; i++) {
    remainder += loads[i;
    sum += remainder >> 10; /* semantically sum += remainder / 1024 */
    remainder &= 甲;
}
```
2. Kahan summation `corr = (t - sum) - y` relies on floating point numbers don't satisfy 乙律 to track rounding error.
    - Compiler optimzation allowes **flowating point 重排（reordering?)**

# Probability
e.g. For binary AND operator, $Pr(output = 1) = 0.25$; $Pr(output = 0) =
0.75$    

|x|y|x AND y|
|:---:|:---:|:---:|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

- Scheduling and Cryptography could be analyzed (designed) with probability and statistics.
    - Scheduler: design to reduce _starvation_ while maintaining
      _priority_ requires probability distribution construction and
      analysis

# Wireless Network (無線網路)
- Error correction, noise reduction, signal recovery...
    - They all require probabilistic methods.
## Exponentialilly Weighted Moving Average (EWMA)
- Recursive definition:
```math
S_t = \alpha x_t = \(1 - \alpha \) S_{t - 1}
```
- This computation involves float and would accumulate error
    - Linux Kernel: find `long`/`int` equivalent representation to do
      floating point math
- Appears in networks, Linux kernel, stocks...

