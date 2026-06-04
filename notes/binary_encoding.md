# 解讀計算機編碼
* The computer has fininte number of bits, but have to represent infinite values.
* The computer performs **modular arithmetic** on addition and multiplication and discarding overflow
  bit.
    * The $\text{mod}$ operation is perfromed automatically by discarding overflow bits.
* Addition requires implementation of an **Abelian Group**
* Real (integer) values can be visualized on a numberline, (integer) values represented by the
  computer lies on a circle/ring since it's finite and it cycles back (wraps around).

# Modular Arithmetic
* "Wraps around"/"Cycle Back" to the smallest element
* Can be visualized as a ring

* $a \mod m$ denotes the **remainder** of $a / m$, if $a = mk + r$, we say $a$ is **congruent** to
  $r \mod m$, denoted $a \equiv r \mod m$
    * Similarly, if $a \neq b$, and the remainders of $a / m$ and $b / m$ are equal, it's obvious
      that $a \mod m = b \mod m \iff a \equiv b \mod m$

# Two's Complement
* Application of modular arithmetic (clock arithmetic that "wraps around" to smallest element
  (usually 0))

Take 8-bit storage as an example, it has $2^8 = 256$ possible binary code ranging from `00000000` to
`11111111`, let `00000000` represents the integer value of $0$, the negative numbers could be
defined starting from $-1$.

Mathematically, $-1$ has to satisfy the equation $-1 + 1 = 0$, translate this to binary encoding:
```
x + 00000001 = 00000000
```

`x` can only be `11111111` by the rules of binary addition. The carry is discarded because of finite
storage space, and `11111111` is a valid encoding.

Similarly, $-2$ shall satisfy $-2 + 1 = -1$, in binary code:
```
x + 00000001 = 11111111
```
`x` shall be `11111110` in this case

What shall $-3$ be then? Above 2 examples suggest $-3 + 1 = -2$ must hold, thus, 
```
x + 00000001 = 11111110
```
and `x` is solved to be `11111101`.

This "recursive approach" could be continued indefinitely provided the encoding of $0$ is defined,
for every positive number representable by given number of bit-width, their negative counter part
(a.k.a complement) $\bar{x}$ is defined if for any positive $x$ in the allowed range,
$x + \bar{x} = 0$.

What is the most negative number using this "recursive" definition and $x + \bar{x} = 0$?
---
Suppose we are only given 8-bits of storage, maximum signed representation is thus `01111111`,
equivalent to 127, its complement shall be the smallest possible integer representable by 8-bits.

it shall satisfy $x + \bar{x} = 0$, in binary code,
```
01111111  + x = 00000000  ⇔
0111 1111 + x = 0000 0000 ⇔
            x = 1000 0001
```

So, numerically `10000001` shall represent -127, and now we have 

$$
\underbrace{127}_{\text{-1 to -127}} + \underbrace{128}_{\text{0 to 127}} = 255
$$

We are missing one encoding for 8-bit storage, which contains 256 binary patterns.

Since we can already represent 128 positive values with `00000000, 00000001, 00000010, ...,
01111111` with regular decimal-to-binary conversion, there should also be 128 negative values for
8-bit storage. From previous construction, the missing value shall be -127 - 1 = -128, its
representation is constructed below.

```
-127 - 1 = -127 + (-1) = 1000 0001 + 1111 1111 = 1000 0000

1000 0001
1111 1111 +)
------------
1000 0000
```

So `10000000` is the smallest integer representable by 8-bits.

## A Short Summary
* Computers can only represent finite number of bits in memory.
    * a $n$-bit computer performs arithmetic modulo $2^n$
* Computer addition: `1 + 0 = 1`; `1 + 1 = [1]0`, `[1]` is the carry bit.
    * in 1 bit storage, that carry bit is discarded, this pattern applies for all fix-width storage.
* Positive integers get encoded by doing "conventional" decimal-to-binary conversion.
* The negative integers are defined as complements to positive integers such that $x + \bar{x} = 0$
  for all positive integer $x$ and their complement $\bar{x}$.
* By establishing the encoding of $-1$ as `11111111` (for 8-bit storage), the encoding of negative
  integers can successively be defined with a "recursive" procedure outlined above.
* Positive integers have 0 in their MSB (sign bit), ranging from `00...01` to `011...11`.
* Negative integers have 1 in their MSB (sign bit), ranging from `11...11` to `100...00`.
* `len(positive_int) + len(negative_int) + 1 = 2^bit_width` shall hold.
* 2's complement work because binary addition naturally implements modulo addition.

# Modular Arithmetic
* "wraps around" the smallest element when operation on any 2 elements "overflows"/"exceeds greatest
  element"
* [Some properties](https://blog.sengxian.com/algorithms/mod-world)

# Basic Properties of a Group
Group = A set $A$ and an operation $\cdot$, sometimes denoted $(A, \cdot)$.
1. Closure 
2. Associativity
3. Exists **identity element** $e$ such that $\forall a \in A, a \cdot e = a$
4. Exists **inverse element** $\bar{a}$ such that $\forall a \in A, a \cdot \bar{a} = e$

# Abelian Group
* A set $A$ together with an operator $\cdot$ that takes 2 elements from $A$ and returns another
  element in $A$ (closure property), $\cdot$ is a place holder for the operation, the group $(A,
  \cdot)$ shall follow:
    * Associativivity:
    * Commutativivity:
    * Distributivity (for multiplication):
    * Have an **identity element** $e$
    * For every element $x \in A$, an **inverse element** $\bar{x}$ exists such that $x \cdot \bar{x} = e$ 

# Fermat's Little Theorem

# Galois Group
* This relates closely to **finite group theory**
* Note on **Modular Inverse**: This can even be used in LeetCode
* Group Theory introduces the notion of **symmetry**: if an identity remains unchanged after some
  transformation, then it is symmetric.
    * e.g. A circle is still a circle if reflected about its diameter.
* 在原文中引入 Galois Group 的主要目的是引入「對稱性」的概念，從而建構「時鐘運算」+ 「1、2
  補數對稱軸」的模型。
