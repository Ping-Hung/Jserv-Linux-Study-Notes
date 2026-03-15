# Jserv-Linux-Study-Notes
- Keep up with the [schedule](https://wiki.csie.ncku.edu.tw/linux/schedule)
- Be aware of what's on the [FB Group](https://www.facebook.com/groups/system.software2026/)
- Flip through [Course Tips and Logistics](https://docs.google.com/presentation/d/1LIP64FQRa9J34ks9rKPmXmNQ-ZhL91qfB9KkF2nr30g/edit)
    - be ware of hyperlinks in slides.

# HW 2 TODO
- [x] <ins>Review HW1 from one student</ins>
- [x] 檢視〈飛蛾為什麼會撲火〉影片內被推翻理論存在的謬誤，並引以為戒。
### 〈分析快慢指標〉
- [ ] Learn GNU perf
- [ ] Learn fast and slow pointer pattern
- [ ] Design experiment using `perf stat -e cache-references,cache-misses,cycles,instructions`
- [ ] Answer other questions in this section
### 探討〈你所不知道的 C 語言：記憶體管理、對齊及硬體特性〉
- [ ] 確實研讀教材
- [ ] 搭配 linux kernel (using `git log`) 回答問題

# Resource Reading Tips
- Consult first hand resource first e.g.
    - `git log` (on Linux kernel)
    - Linux Kernel Mailing-List (LKML)
    - Authorized sources (gcc standards/glibc manuals)
- AI工具是輔助性質，可用來撰寫測試程式碼和收集資訊，但主要的**推測、查證、分析，和討論**，都該由人類進行
- When learning math (or related) materials, focus on
  definition + properties
    - So you know implementation limitations

# HW Tips:
- **MUST** list out where you are confused/not understand.
    - Be as specific as possible, list out concept, section,
      page...
- Don't expect to finish _everything perfectly on-time_, but you **MUST SHOW EFFORT**.
- Learning goal: be able to describe phenomenon with
  math/physics, if cannot, your understanding isn't as
  thorough.
    - Must be as truthful to yourself as possible.
        
# Agenda Tips:
- **The First 6 Weeks** are the most intense weeks
    - You might have to pull all-nighters
    - HW every week.
        - 16-hours of commitment
- 18 weeks (regular scheduled) + 2 extra weeks


# Readings (A changing list)
- [x] [核心定點數與EWMA](https://hackmd.io/@sysprog/HJEPQn5ubx)
- [x] [初步解讀浮點數](https://hackmd.io/@sysprog/B1dc2oq_Wx)
- [ ] [HW1](https://hackmd.io/@sysprog/linux2026-warmup)

# Background Knowledge
* Heard-of (but not fully mastered) concepts/topics/ideas are checked
1. Data Structures:
    - [x] Circular linked-lists
    - [x] Red-Black Tree
    - [x] Abstract Data Type
2. Computer Organization and Architecture:
    - [x] Bitwise operation
    - [x] Binary representation
    - [x] Floating point
    - [x] Cache
    - [ ] Memory
    - [x] ISA
    - [ ] SMP
    - [ ] Atomics
3. Algorithms
    - [x] Recursive programming
    - [x] Time/Space complexity analysis
    - [ ] Worst-Case execution time
    - [ ] Concurrent algorithms

4. C Programming Language
    - [x] C99/C11 spec
    - [x] Pointers(addersses)
    - [x] OOP
    - [ ] Performance benchmark + analysis
    - [x] Debugging (Assume GDB and Valgrind)
    - [x] Design patterns
    - [x] Unit Test

5. Mathematics
    - [x] Statistics and Probability
        - Like statistical mechanics, 足以模擬微小尺度程式運作的各種原理
    - [x] Number Theory and Abstract Algebra
        - Foundation of computer (binary) number system and cryptography
    - [ ] Queuing Theory
        - Math for CPU scheduling
    - [ ] Statistical Mechanics

6. Miscellaneous
    - [ ] Cyber-Security
    - [ ] Cryptography
    - [ ] Computer Graphics
    - [ ] Computer Networks
    - [ ] 異質多核運算 (Heterogeneous comoputing)
    - [x] Code Quality


# Links
1. [context switch and spinlock: probability and statistics](https://hackmd.io/@sysprog/linux-spinlock-scalability)
2. [核心定點數與EWMA](https://hackmd.io/@sysprog/HJEPQn5ubx)
3. [初步解讀浮點數](https://hackmd.io/@sysprog/B1dc2oq_Wx)
3. [How probability and information entropy are used in modern OS](https://hackmd.io/@sysprog/from-entropy-to-os)

# How to Follow Along
1. Do HW Assignments
2. Be truthful to yourself
3. Read Course Material (Mostly HackMD files online)
4. Join Discussion

# Learning Frameworks/Tips
## Think On Paper
When encounter new concepts
1. **_Make it wrong:_**
    - Jot down as many concepts as possible
    - Conjecture/Infer how these concepts connect to each other
    - It COULD be **wrong**, but that's totally <mark>**FINE**</mark>
2. **_Make it shorter_:**
    - Condense and distill
    - Create mental cues from notes taken in step 1
3. **_Make it Again_:**
    - Fix your notes so it refelects the actual, correct understanding
    - Reorganize + Clean up to strengthen retention
    - **Tip**: look at your notes, if they are 
        1. messy or overwhelming or
        2. contains mistakes 
    → reorganize.

# Resources
1. [C99 Standards](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf)
2. [你所不知道的C語言](https://hackmd.io/@sysprog/c-prog/%2F%40sysprog%2Fc-programming)
