# Git log tips
```
git log [--grep "pattern"]+
```
* Limit the commits output to ones with a log message that matches
  the specified pattern (regular expression). With more than one
  --grep=<pattern>, commits whose message matches any of the given
  patterns are chosen

* `[...]+`: what's in the braket appears one or more times.
___

```
git log --grep "pattern" --all-match
```
* Limit the commits output to ones that match all given --grep, instead of ones that match at least one.

# "Syntax" Hints:
```
index A .. B
```
* This meant file-level difference
* A is the blob (file-content) *before*; B is the blob *after*

* Source: [ChatGPT](https://chatgpt.com/s/t_69c1b39dab408191b16e7d32ee748fcf)
