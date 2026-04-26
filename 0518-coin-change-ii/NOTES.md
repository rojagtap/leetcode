---
problem_id: '0518'
platform: 'leetcode'
title: 'Coin Change II'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0518-coin-change-ii'
primary_tags:
  - '[[dp]]'
  - '[[take-dont-take]]'
subtle_tags:
  - '[[dp_translation_friction]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
  - '[[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]'
  - '[[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]'
  - '[[leetcode/0198-house-robber/NOTES|0198-house-robber]]'
  - '[[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]'
---

## Explanations

The solver explored two fundamentally different recursion structures. Approach 1 loops over all coins at each level, leading to an extra factor of n in complexity. Approach 2 recognizes the standard take/don't-take pattern where each coin is either used (with repetition) or skipped, yielding the optimal `O(n * amount)`. The fact that six total implementations are retained (two approaches times three optimization levels) suggests the solver used this problem to practice the full DP translation pipeline.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error

### Mistake Notes
- [[wrong_path]]: first approach used a loop from start to end at each recursion level, resulting in `O(n^2 * amount)`; then recognized classic take/don't-take reduces to `O(n * amount)`

### Related Reasoning
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0198-house-robber/NOTES|0198-house-robber]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]: both show [[dp_translation_friction]] with shared [[wrong_path]]

### Signals
- Two complete approach families retained: 'approach 1: run loop from start to end' and 'approach 2: classic take/dont take'
- Each approach has `backtracking -> memo -> bottom-up` versions
- 'this is a simple take/don't take problem' appears only at approach 2, suggesting approach 1 was tried first
