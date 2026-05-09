---
problem_id: '3922'
platform: 'leetcode'
title: 'Minimum Flips to Make Binary String Coherent'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '3922-minimum-flips-to-make-binary-string-coherent'
primary_tags:
  - '[[greedy]]'
  - '[[math]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[proof_gap]]'
  - '[[wrong_path]]'
related: []
---

## Explanations

The structural lemma the iterations were chasing: forbidding `011` and `110` as *subsequences* (not substrings) collapses the valid configurations to just three families -- (a) at most one `1`, (b) no `0`, or (c) exactly two `1`s sitting at the very endpoints of the string with anything in between. Family (c) is the trap. Once you have two `1`s, any `0` to the right of both creates `1,1,0` and any `0` to the left of both creates `0,1,1`, so the only place every `0` can live is *strictly between* the two `1`s -- which forces the `1`s to be at index 0 and `n - 1`. So when `zeros > 0 && ones > 1`, the answer is the cheapest of "kill all zeros" (cost `zeros`) and "keep at most `k` ones" where `k = 2` if both endpoints are already `1` (cost `ones - 2`) and `k = 1` otherwise (cost `ones - 1`). We do not get to *create* family (c) by flipping the endpoints, because flipping an endpoint just spends 1 flip without reducing the obligation to kill the other 1s, and the bookkeeping never beats `ones - 1`.

Future-self trap: the seven commented-out classes at the bottom are eight refinement passes through the same shape -- count `ones` and `zeros`, then adjust the formula one case at a time. The case the iterations were finding was always the endpoint case (`s[0] == '1' && s[n - 1] == '1'`), which the early versions either missed entirely or special-cased only for `ones == 2`. Future-self should write the lemma down first and let the formula fall out, instead of patching the formula until the failing tests disappear. The defensive comment names `1001` and `1101` as the "viscious" inputs; both are exactly the family (c) signal.

### Mistake Notes
- [[proof_gap]]: the active formula `min(zeros, ones - 2)` for the both-endpoints-`1` case is correct but no derivation is written; the eight commented-out versions are the only record of why each earlier formula failed
- [[wrong_path]]: versions 1-7 (preserved as a stacked block comment) commit to wrong formulas before the endpoint guard appears; version 5 returns `ones - 1` without the `min` against `zeros`, so any case with few zeros would have been over-counted

### Signals
- block comment opens with `i went trial and error for this one. the ones that were especially viscious were 1001 and 1101 basically there are two one's at the end`
- the entire iteration history is preserved at the bottom of the file as commented classes labeled `1` through `7`, with each class showing one more case branch than the previous
- final solution leans entirely on three counts (`ones`, `zeros`, `n`) and the two endpoint characters; no scan beyond the initial tally
