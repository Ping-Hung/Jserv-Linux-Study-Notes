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
|$x_n$|Data at the $n$th iteration|

## $\alpha$ Value's Impact on the Average ($S_n$)
|small \alpha|large \alpha|
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


# PELT 的排程負載追蹤
## Vocabulary
* 捲積核: Convolution Kernel
    - Convolution matrix (array) in discrete convolution
    - The integrand in continuous convolution
