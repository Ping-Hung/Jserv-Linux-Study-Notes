# Review Criteria
- [ ] 給定題目的回覆是否完整
- [ ] 是否參照權威材料去解讀和推理
- [ ] 是否設計實驗去驗證、論述和後續討論，落實上述 "Code Review" 提出的原則
- [ ] 實驗設計的不足處、涵蓋程度是否全面，以及後續的改進空間
- [ ] 共筆行文是否流暢且具體，結構規劃是否清晰，且以第一手材料為主要依循，並細緻驗證
- [ ] 斟酌在選定的 GitHub repository 留下 code review 意見。
- [ ] 嘗試回覆學員提出的問題。

# Review Comments
- [ ] 為何計算機的加法在固定 $k$ 位元下，本質等價於 $\mathbb{Z}/2^k\mathbb{Z}$ 上的加法？
:::warning
> 而一般計算機使用的二補數只是編碼對應元素不同而已。
請針對這點解釋一下。
:::

- [ ] 為何 $x \% 2^n\equiv x \& (2^n - 1)$ 僅對 unsigned 或非負整數安全？從 CVE/CWE 找到相關資訊安全的議題

:::warning
1. 可有辦法以 bit-wise AND operator 的特性推導證明？
2. 請問哪份教材呢？
3. 翻閱文中給出的超連結（C11 規範）

> 6 When integers are divided, the result of the / operator is the
> algebraic quotient with any fractional part discarded.105) If the
> quotient a/b is representable, the expression (a/b)*b + a%b shall equal
> a; otherwise, the behavior of both a/b and a%b is undefined.

> Footnotes
> 105) This is often called "truncation toward zero". 

可以根據 "the result of the / operator is the algebraic quotient with any fractional part discarded." 和 "This is often called truncation towards zero" 推得 "truncation towards zero" 意為「捨棄商的小數部份」；結合「保留被除數的正負號」，請問如何得知 「所以在負數的情況下就辦法確保兩者相等」？ (Hint: 將你列舉的範例結合補數系統和 AND 算子的特性加以解釋/證明)

4. 請列出相關的 CVE/CWE 議題。
:::

- [ ] 比較 concurrent 與 parallel 的語意差異，並說明為何「並行」較貼近 concurrent 的本意

:::warning
- Jserv 老師可能會要你去好好查字典（笑）。  
- 提議翻閱牛津英語辭典或 Merriam Webster Dictionary 查看其中對兩自的區別並結合 parallel programming 和 concurrent programming 的語境解釋區別。

:::

- [ ] 分析： `double x[3]; int *p = (int *)&x[0]; printf("%d\n", *(p+1));`
    1. 為何 pointer arithmetic 的單位取決於 type？
    2. 這是否涉及 strict aliasing 問題？
    3. 在 ARMv5 或 RISC-V 上可能出現什麼錯誤？
:::warning
請說明在 ARMv5 或 RISC-V 上可能出現什麼錯誤。
:::
