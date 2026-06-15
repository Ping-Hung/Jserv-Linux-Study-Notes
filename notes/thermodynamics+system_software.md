# 2nd Law of Thermo and System Software
## 宏觀穩定性 (Macroscopic Stability?) 的可檢驗定義與關鍵來源
1. 延遲分佈 (Latency Distribution) 尾部形狀可重現
2. 吞吐量時間序列可分段視為平穩 (stable throughput time-series?)
3. 排程誤差分佈無長期漂移 (scheduling error distribution does not have long term drifts?)

Above three bullets must ***all be satisfied*** for a system to be macroscopically stable (?) under
load.

## Latency
* **Latency is a distribution**, shall be described using *statistical language* (e.g. confidence
  intervals).
* **Latency** is subject to load (how much work is asked to be done for a system? e.g. requests/second)

* In the context of Linux, **Latency Distribution** is a statistical measurment/projection of 2 main
  core subsystems:
    * *timekeeping and Tick Architecture*
    * *Enlargement of (distribution) tail from recycling/releasing memory *


## Vocabulary
* 尾端延遲 (Tail Latency): unusually high response times experienced by the slowest fraction of requests in a computer system.
    * PR99.9: The latency being discussed is the 0.1% that is slower than the 99.9%.
* Data Drift/Model Drift (漂移）: a **change in the statistical properties and characteristics** of the
  input data (ML/AI definition).
## Sources
1. [Tail Latency Explained](https://medium.com/beyond-localhost/tail-latency-explained-the-way-staff-engineers-actually-think-about-it-e385db267b6e)
2. [The First Law of Latency](https://medium.com/engineers-optimizely/the-first-law-of-latency-there-is-no-the-latency-of-the-system-20206ac62ae)
