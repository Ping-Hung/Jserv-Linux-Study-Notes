# 探討 <[解讀計算機編碼](https://hackmd.io/@sysprog/binary-representation)>
- Q1: 為何計算機的加法在固定$k$位元下，本質等價於  
<mark>
$$
\mathbb{Z}/2^{k}\mathbb{Z}
$$
上的加法</mark>?
- A1: $\mathbb{Z}/2^{k}\mathbb{Z}$ means "ring of integers modulo $2^{k}$", if addition ($+$) is the only operator of concern, then $\(\mathbb{Z}/2^{k}\mathbb{Z}, +\)$ is an Abelian group, which 
    - Satisfies Associativity laws.
    - Satisfies Communitative laws.
    - Has identity element $0$ for the entire set.
    - $\forall x \in \(\mathbb{Z}/2^{k}\mathbb{Z}, +\), \exists \bar{x}$ such that $x + \bar{x} = 0$.
The following attempts to show how computer addition in fixed k-bits satisfies requirements listed above.
    

- Q2:為何「允許溢位」反而保證封閉性？若不允許溢位，會破壞哪些群的性質？ 
- A2: 


# References
1. https://www.math.purdue.edu/~arapura/algebra/algebra.pdf
