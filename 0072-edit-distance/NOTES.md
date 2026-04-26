---
problem_id: '0072'
platform: 'leetcode'
title: 'Edit Distance'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0072-edit-distance'
primary_tags:
  - '[[dp]]'
subtle_tags:
  - '[[dp_translation_friction]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
  - '[[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]'
  - '[[leetcode/0198-house-robber/NOTES|0198-house-robber]]'
  - '[[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]'
  - '[[leetcode/0312-burst-balloons/NOTES|0312-burst-balloons]]'
---

## Explanations

The solver walked the complete DP translation pipeline from exponential backtracking to space-optimized bottom-up, preserving all four versions. The detailed comments explaining what each operation (insert, delete, substitute) means in terms of index movement suggest the mapping from conceptual operations to index transitions required careful reasoning. The space optimization from 2D to two rolling rows is the final mechanical step.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error

### Mistake Notes
- [[wrong_path]]: four approaches preserved: backtracking `TLE`, memoized backtracking, bottom-up 2D, space-optimized 1D -- full translation pipeline

### Related Reasoning
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0198-house-robber/NOTES|0198-house-robber]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0312-burst-balloons/NOTES|0312-burst-balloons]]: both show [[dp_translation_friction]] with shared [[wrong_path]]

### Signals
- similar to take/don't take, just 3 choices
- if inserting, that means we inserted a character of `word2` into `word1` before `word1[i]`, so move `j` ahead
- if deleting, we removed a character from `word1`, so we try the remaining `word1` and go to `i + 1`
- since we only need the `(i + 1)`th and `i`th rows from the DP array, we can keep only those
- four full approaches preserved as commented-out code
