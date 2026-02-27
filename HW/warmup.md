# 探討 <[解讀計算機編碼](https://hackmd.io/@sysprog/binary-representation)>
## **Q1:** 為何計算機的加法在固定 $k$ 位元下，本質等價於 <mark> $\mathbb{Z}/2^{k}\mathbb{Z}$ 上的加法</mark>?  
**A1:** $\mathbb{Z}/2^{k}\mathbb{Z}$ means "ring of integers modulo $2^{k}$", if addition ($+$) is the only operator of concern, then
$G = \(\mathbb{Z}/2^{k}\mathbb{Z}, +\)$ is an Abelian group, which 

1. Satisfies Associativity laws, formally:  
$$\forall x, y, z \in G, x + y + z = (x + y) + z = x + (y + z)$$.
2. Satisfies Commutativity, formally: 
$$\forall x, y \in G, x + y = y + x $$.
3. Has an unique identity element $0$ over the entire set.
4. $\forall x \in G, \exists \bar{x}$ such that $x + \bar{x} = 0$.

The following attempts to show how computer addition in fixed k-bits satisfies requirements listed above.  

Let's start with the simplist property, the existence of an identity element
$0$ (property 3).  
For a $k$ bit integer, regardless of signedness, `0b0000...0 (k-bits long)` is usually the unique binary encoding of the $0$ element.

The second property to show is commtativity (property 2).  
Suppose we have 2 k-bit integers `x` and `y`, one trivial hardware implementation of such operation is the (ripple carry) full adder, which keep tracks of a carry `c` while performing `XOR` operations on each bit of `x` and `y`, starting from lowest significant bit (LSB).   
More formally, for each bit (`x_i`, `y_i`) of `x`, `y`, 
```
    s(sum) := x_i XOR y_i
    c(carry) := x_i AND y_i
```

Observe that both operations (`XOR` and `AND`) composing addition obeys commutativity, which implies addition of k-bit integers is also commutative.  

To show the 2 remaining properties (existence of inverse for all elements in $G$ and associativity), we'll assume 2's complement as the standard definition for (negative) inverse and integer overflow is permitted.

    

## **Q2:** 為何「允許溢位」反而保證封閉性？若不允許溢位，會破壞哪些群的性質？  
**A2:** 


# References
1. https://www.math.purdue.edu/~arapura/algebra/algebra.pdf
