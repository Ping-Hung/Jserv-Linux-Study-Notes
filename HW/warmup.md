# 探討 <[解讀計算機編碼](https://hackmd.io/@sysprog/binary-representation)>
## **Q1:** 為何計算機的加法在固定 $k$ 位元下，本質等價於 <mark> $\mathbb{Z}/2^{k}\mathbb{Z}$ 上的加法</mark>?  
**A1:** $\mathbb{Z}/2^{k}\mathbb{Z}$ means "ring of integers modulo $2^{k}$",
or more informally, "set of integers that wraps around $2^k$" if addition ($+$)
is the only operator of concern, then $G = \(\mathbb{Z}/2^{k}\mathbb{Z}, +\)$
is an Abelian group, which 

1. Satisfies Associativity, formally:  
$$\forall x, y, z \in G, x + y + z = (x + y) + z = x + (y + z)$$.
2. Satisfies Commutativity, formally: 
$$\forall x, y \in G, x + y = y + x $$.
3. Has an unique identity element $0$ over the entire set.
4. $\forall x \in G, \exists \bar{x}$ such that $x + \bar{x} = 0$.

The following attempts to show how computer addition in fixed k-bits satisfies
requirements listed above.  

Let's start with the simplist property, the existence of an identity element
$0$ (property 3).  

For a $k$ bit integer, regardless of signedness, `0b0000...0 (k-bits long)` is
usually the unique binary encoding of the $0$ element.

The second property to show is commtativity (property 2).  

Suppose we are adding 2 k-bit integers `x` and `y`, one trivial hardware
implementation of such operation is the **(ripple carry) full adder**, which keep
tracks of a carry `c` while performing bitwise `XOR` operations `x` and `y`,
starting from lowest significant bit (LSB).   

More formally, for each bit (`x_i`, `y_i`) of `x`, `y`, 

```
    sum:    s = x_i XOR y_i
    carry:  c = x_i AND y_i
```

Observe that both operations (`XOR` and `AND`) composing addition are
commutative, which implies addition of k-bit integers is also commutative.  

To show the 2 remaining properties, associativity and existence of inverse
elements $\forall x \in \mathbb{Z}/2^{k}\mathbb{Z} $, we'll first treat
addition in this domain as additive modulo to ensure addition is closed in the
domain.

**Proposition**: Addition modulo in the ring of integers modulo $2^k$
($\mathbb{Z}/2^{k}\mathbb{Z}$) is _closed_ under addition.  

**Proof:**  
$\forall x,y \in \mathbb{Z}/2^{k}\mathbb{Z}$, by definition of the ring,

```math
\begin{align} 
    x &\equiv a \pmod{2^k} \\ 
    y &\equiv b \pmod{2^k} \\
    \exists a, b \in \mathbb{Z}
\end{align}
```

Their (modulo) sum is thus  
```math
x + y \pmod{2^k} \equiv (a \pmod{2^k} + a \pmod {2^k}) \pmod{2^k},
```
an element of $\mathbb{Z}/2^{k}\mathbb{Z}$ by definition, which demonstrates
closure of (modulo) addition.

We'll proceed to verify **proposition** (closure property), associativity, and
the existence of inverse elements in integer computer arithmetic.

**Proposition (Closure) Proof**:  
Modern computers represent (possibly) infinite integers with finite bits of
storage and permits overflow to model $\mathbb{Z}/2^{k}\mathbb{Z}$ and ensure _closure_.

| |value|pattern/encoding|
|:---|:---|:---|
|signed max| $2^{k-1} - 1$| `0b01...1`, k - 1 `1`'s, MSB = 0|
|unsigned max| $2^k - 1$| `0b1...1`, k `1`'s, MSB = 1|

Addition will still be performed using aforementioned **(ripple carry) full adder**, with premission to overflow.  
This meant 
```
0b11...1 (unsigned max) + 1 (0b1) = 0b00...0,
```
ignoring MSB's carry. Similarly, `0b11...1 + 2 = 0b00...1`, `0b11...1 + 3 = 0b00...10`, and the list goes on.      
Observe that this "wraps around" behavior (increment $2^{k}$ by an arbitrary integer value $m$ yields $m - 1$) ensures the sum to
be a member of $\mathbb{Z}/2^{k}\mathbb{Z}$, which preserves _closure_. Similar reasoning could be applied to signed values.

**Inverse Element Proof**:  
We previously showed that `0b00...0` (k-bits of 0) is the encoding for the $0$ element, now we have to demonstrate how modern 
computers modelled additive inverse (negative integers) with finit bits.

Modern computers use 2's complement to model additive inverse of signed integers. Given a signed value `x`, its 2's complement is
`~x + 1`, where `~` inverts every bit in `x`. Combining this definition with the permission to overflow and ignore the carry bit,
we can show $\forall x \in \mathbb{Z}/2^k\mathbb{Z}, \exists \bar{x}$ such that $x + \bar{x} = 0$.


Suppose `x` is the maximum of all `k` bit signed values, and `-x` is its 2's complement.

```
x = 0b01...1 (k - 1 1's)
-x = ~x + 1 = ~(0b01...1) + 1 = 0b10...01 (k - 2 0's between 2 1'2)
```

Adding them up, it is evident that `-x` is indeed the inverse element of `x`
```
    x = 0b01...11
+) -x = 0b10...01
_____________________
   0  = 0b0000000
```

For values smaller than the signed maximum of `k` bit values (`x`, which is $2^{k-1} - 1$), subtract their difference from `x` then
add it to `-x`. This way, we find a way to "create" all additive inverse for `k` bit signed numbers.



    

## **Q2:** 為何「允許溢位」反而保證封閉性？若不允許溢位，會破壞哪些群的性質？  
**A2:** 


# References
1. https://www.math.purdue.edu/~arapura/algebra/algebra.pdf
2. https://chatgpt.com/share/69a2d1e1-7258-800f-af92-b1765d6a7075
