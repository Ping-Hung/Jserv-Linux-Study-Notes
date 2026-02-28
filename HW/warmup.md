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
implementation of such operation is the (ripple carry) full adder, which keep
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
storage and permits overflow to model $\mathbb{Z}/2^{k}\mathbb{Z}$ and _closure_.

| |value|pattern/encoding|
|:---|:---|:---|
|signed max| $2^(k-1) - 1$| `0b01...1`, k - 1 `1`'s, MSB = 0|
|unsigned max| $2^k - 1$| `0b1...1`, k `1`'s, MSB = 1|

Suppose `k = 8`, i.e. 8-bits of storage is alloted, for signed integers





    

## **Q2:** 為何「允許溢位」反而保證封閉性？若不允許溢位，會破壞哪些群的性質？  
**A2:** 


# References
1. https://www.math.purdue.edu/~arapura/algebra/algebra.pdf
2. https://chatgpt.com/share/69a2d1e1-7258-800f-af92-b1765d6a7075
