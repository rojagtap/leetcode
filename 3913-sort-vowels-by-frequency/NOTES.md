---
problem_id: '3913'
platform: 'leetcode'
title: 'Sort Vowels by Frequency'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '3913-sort-vowels-by-frequency'
primary_tags:
  - '[[hashmap]]'
  - '[[sorting]]'
candidate_tags: []
mistakes: []
related: []
---

## Explanations

`no_signal`. The solver collapses the workload by sorting only the 5-key vowel set rather than the substring of vowel positions: count `freqmap`, capture `idxmap` for first-occurrence tiebreaks, sort the 5 vowels by `(freq desc, first-occurrence asc)`, then refill the saved positions in order, advancing `curr` as each vowel's count drains. The only mildly sharp detail is the comparator's zero-frequency guard (`if (!freqmap[a - 'a']) return false; if (!freqmap[b - 'a']) return true;`) which sinks unused vowels to the back so `vowels[curr]` cannot fall onto a dead key during the refill. Defensive, not friction.

### Signals
- comparator hard-codes the zero-frequency case at the top, separate from the freq comparison -- a deliberate guard rather than discovered after a wrong answer
- only 5 keys are sorted; the per-position writes happen in a single pass through `pos`
