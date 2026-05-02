# EWMA (Exponentially Weighted Moving Average)
* "Discount"/"Shrink"/"Decays" historical record.
    - Signals/contributions happend long ago has less influence on current value.
* This design is most suitable to real-time monitoring scenarios, (e.g. wifisignal strength, block
  I/O delay, network throughput...etc)
    - recent/current trends have far more weights than historical records.

# EWMA Definition and Properties
```math
    S_{n} = \alpha \cdot x_{n} + (1 - \alpha) \cdot S_{n-1}, 0 < \alpha \leq 1
```

|parameters|meaning|
|:---:|:---:|
|$S_n$|The moving average at the $n$ th iteration|
|$\alpha$|The exponential weight: controls how sensitive $S_n$ is to historical data|
|$x_n$|Data at the $n$ th iteration|

## $\alpha$ Value's Impact on the Average ($S_n$)
|small $\alpha$|large $\alpha$|
|------------|------------|
|more weights on historical data | more weights on recent records|
|Slower response to recently added data (long memory) | Quick response to newly added data (short memory)|

* Smaller $\alpha$, more weight on historical records; larger $\alpha$, more weights on recent
  records.

## ("Usefulness"/"Viability") Properties
1. Use only a single *state-variable* $S_n$, not the entire historical record.
    - Lower cost on memory usage
2. "Discounting" historical record by $1 - \alpha$ in each iteration naturally suppresses the impact
   of historical data (noise) on recent/current data/trends.
   - Removes "unrelevant" info from long-ago when running this algorithm in long time window.
3. Easy to switch from "historical noise reduction" to "real-time response" by changing $\alpha$.

# EWMA: Fixed-Point Calculation 
* In the kernel, using floating point values for EWMA is not-viable.
    - Every context switch requires saving and restoring fo FPU registers.
    - Has significant delay
* [Fixed-point calculation to save this](https://hackmd.io/@sysprog/HJEPQn5ubx?stext=958%3A16%3A0%3A1777690639%3As6Gg4E)
## Notes
* $\alpha$ restricted to $1/W$ ($W$ == `_weighted_rcp`, must be $2^n$)
* $w = \log_{2}{W}$
* Replace multiplication and division with shifts.
* Multiply real EWMA value by $2^p$ to preserve precision (after the decimal point)

# PELT 的排程負載追蹤
## Discrete Expansions after $n$ steps
### Regular Formula
```math
    \begin{align*}
        S_{n} &= \alpha \cdot x_{n} + (1 - \alpha) \cdot S_{n-1}, 0 < \alpha \leq 1  \iff \\
        S_n &=  \alpha  \sum_{i = 0}^{n - 1} (1 - \alpha)^{n - i} x_i + (1 + \alpha)^{n} x_0 
    \end{align*}
```
### PELT Version
* $k := \text{exp}(- \Delta t / \tau)$, equivalent to $1 - \alpha$ in regular EWMA formula
* $\Delta t$: this is not a fixed value, it means *time difference*
* $\tau$ is the ***time constant*** that "controls" how frequently a decay happens.
* Default half-life (預設半衰期 $t_{1/2}$): 32 ms, use this to derive $\tau$
```math
    \tau = t_{1/2} / \ln 2
```

**Formula (After Discrete n-steps Expansion)**
```math
    \begin{align*}
        u_{n} &= (1 - k) \sum_{i = 0}^{n - 1} k^{n - i} r_{i} + k^n r_0  \iff \\
        u[n] &= (1 - k) \sum_{i = 0}^{n - 1} k^{n - i} r[i] + k^n r[0]  
    \end{align*}
```

|parameters|meaning|
|----------|-------|
|$u_n$|load estimate|
|$r_n$|CPU 佔用比例; $0 \leq r_n \leq 1$|

**Convolution Integral: Generalization from Discrete to Continuous Time** 
```math
    u(t) = \frac{1}{\tau} \int_{- \infty}^{t} r(s) e^{- \frac{t - s}{\tau}} ds
```
### Important Takaways
* $\Delta t$: not a fixed value, it means ***time difference***
* $\tau$ is the ***time constant*** that "controls" how frequently a decay happens.
* View convolution here as a fancier "weighted sum" over the interval $(-\infty, t]$. The weight
  varies as the time-difference $\Delta t$ between $t$ and $s$ increases.
## Vocabulary
* 捲積核: Convolution Kernel
    - Convolution matrix (array) in discrete convolution
    - The integrand in continuous convolution

# Heavy-Tailed Distribution (重尾分佈）
* **Definition**: Distribution for which extreme events happens with a far higher probability than
  normal distribution-like exponential decay distributions.
    * Extreme/abnormal events usually happens at the *tail* of normal distributions, maybe the name
      *Heavy-tailed* comes from here.
    * 現實世界的網路流量、雲端資源使用模式和 CPU 工作負載皆呈現此類分布，短暫但強度極高的負載尖峰出現的頻率不可忽視。

