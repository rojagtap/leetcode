---
problem_id: '0097'
platform: 'leetcode'
title: 'Interleaving String'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0097-interleaving-string'
primary_tags:
  - '[[dp]]'
subtle_tags:
  - '[[dp_translation_friction]]'
  - '[[state_variable_minimization]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0198-house-robber/NOTES|0198-house-robber]]'
  - '[[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]'
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
  - '[[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]'
---

## Explanations

The solver explicitly noted the state variable reduction from `(i, j, k)` to `(i, j)` by recognizing `k = i + j`, which is preserved in the commented-out backtracking code showing the original three-parameter version. This is a textbook state_variable_minimization moment. The full four-version pipeline from backtracking that hit `TLE` to space-optimized bottom-up shows the standard dp_translation_friction progression.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error
- [[state_variable_minimization]]: realizing a state variable in the recurrence is redundant because it's derivable from others, reducing dimensionality of the DP

### Mistake Notes
- [[wrong_path]]: four approaches preserved: backtracking that hit `TLE`, memoized, bottom-up 2D, space-optimized 1D -- full pipeline

### Related Reasoning
- [[leetcode/0198-house-robber/NOTES|0198-house-robber]]: both show [[dp_translation_friction]] and [[state_variable_minimization]] with shared [[wrong_path]]
- [[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]: both show [[dp_translation_friction]] and [[state_variable_minimization]] with shared [[wrong_path]]
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: both show [[dp_translation_friction]] and [[state_variable_minimization]]
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]: both show [[dp_translation_friction]] with shared [[wrong_path]]

### Signals
- but `k = i + j`, so we can condense it to `(i, j)` for memoization
- notice that `k = i + j` always holds
- since we only need the ith and the (i + 1)th row, we can use a 1-D dp array instead
- commented-out initial version with explicit `k` parameter before recognizing `k = i + j`
