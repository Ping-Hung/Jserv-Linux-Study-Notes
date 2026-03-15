# Review Criteria
- [ ] 給定題目的回覆是否完整
- [ ] 是否參照權威材料去解讀和推理
- [ ] 是否設計實驗去驗證、論述和後續討論，落實上述 "Code Review" 提出的原則
- [ ] 實驗設計的不足處、涵蓋程度是否全面，以及後續的改進空間
- [ ] 共筆行文是否流暢且具體，結構規劃是否清晰，且以第一手材料為主要依循，並細緻驗證
- [ ] 斟酌在選定的 GitHub repository 留下 code review 意見。
- [ ] 嘗試回覆學員提出的問題。

# Code Review Tips (and Mindset of a Constructive Code Reviewer) 
1. 不盲目挑出錯誤，而是思考如何讓程式碼更好。
2. 應以「我們如何讓這段程式碼更好」為出發點，而不是單純指出問題。
3. 將審閱視為合作過程，而非批評個人能力。
4. 避免預設作者的動機（如預設對方沒有閱讀文件）。
5. 直接指出觀察到的問題，並詢問設計考量。

# Technical Writing Tips
**Core Idea**: write in so the reader could understand quickly and easily.  

## Sentences
- 1 idea per sentence. Break long, compound sentence with multiple ideas into several short ones each containing 1 idea.
- Active voice >> passive voice
- Omit filler words. E.g.
    - This is to say that...
    - It should be noted that...

## Verbs
- **Be precise and unambiguous**, e.g
```
    perform, handle, deal with << compute parse, allocate, send
    |_________________________|   |____________________________|
                |                               |
                v                               v
        ambiguous and abstract  <<  precise description of behavior
```

## Nouns and Jargons (Technical (Reserved) Words)
- Be consistent throughout the entire doc.

## Paragraphs
- One idea per paragraph.
- Shall present the idea in sentences, following logical structure.

## Lists
- 若一段文字包含多個並列概念時，清單通常比長句更容易閱讀。
- 如果項目之間存在順序關係，例如操作步驟，應使用編號。若順序不重要，則使用項目清單。
- 清單中的項目應保持語法一致。例如所有項目都以動詞開頭，或都以名詞片語開頭。這種平行結構能顯著提高可讀性。

## Reader Centric Writing
Always ask
1. Who's the reader
2. What does the reader _already know_?
3. What does the reader _need to know_?


