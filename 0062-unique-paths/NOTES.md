---
problem_id: '0062'
platform: 'leetcode'
title: 'Unique Paths'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0062-unique-paths'
primary_tags:
  - '[[dp]]'
subtle_tags:
  - '[[dp_translation_friction]]'
  - '[[subproblem_independence_recognition]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0312-burst-balloons/NOTES|0312-burst-balloons]]'
  - '[[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]'
  - '[[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]'
  - '[[leetcode/0198-house-robber/NOTES|0198-house-robber]]'
  - '[[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]'
---

## Explanations

The solver walked through the full DFS-to-memo-to-tabular pipeline, with each step preserved as commented-out code. The comment about DFS "going to the end and then coming back" being overhead suggests the bottom-up reframing required recognizing that the traversal order can be inverted. The subproblem independence (each cell's count depends only on its right and bottom neighbors) is the key insight enabling the clean tabular form.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error
- [[subproblem_independence_recognition]]: the critical realization that decomposed subproblems share no state, enabling clean memoization — often the hardest insight in interval/partition DP

### Mistake Notes
- [[wrong_path]]: started with plain DFS (`TLE`), then added memoization, then translated to bottom-up tabular DP

### Related Reasoning
- [[leetcode/0312-burst-balloons/NOTES|0312-burst-balloons]]: both show [[dp_translation_friction]] and [[subproblem_independence_recognition]] with shared [[wrong_path]]
- [[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0198-house-robber/NOTES|0198-house-robber]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]: both show [[dp_translation_friction]] with shared [[wrong_path]]

### Signals
- the basic approach is to `dfs` until you reach `(m - 1, n - 1)`; this will be `O(2^mn)`
- instead, we can cache the result for all given further i, j pairs
- in dfs, we first go to the end and then come back which is overhead as we already know where the end is
- so to avoid this, since we are anyway going to each cell once and returning its count, we can traverse the grid directly in reverse
- three approaches preserved: plain DFS (`TLE`), memoized DFS, tabular bottom-up
