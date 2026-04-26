---
problem_id: '0198'
platform: 'leetcode'
title: 'House Robber'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0198-house-robber'
primary_tags:
  - '[[dp]]'
subtle_tags:
  - '[[dp_translation_friction]]'
  - '[[state_variable_minimization]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]'
  - '[[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]'
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
  - '[[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]'
---

## Explanations

The solver progressed through three stages: naive recursion (`TLE`), array-based DP, and finally space-optimized DP using only three rolling variables. The intermediate "easier to understand" comment suggests the space optimization step required deliberate reasoning about which previous states are actually needed.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error
- [[state_variable_minimization]]: realizing a state variable in the recurrence is redundant because it's derivable from others, reducing dimensionality of the DP

### Mistake Notes
- [[wrong_path]]: Recursive `O(2^n)` approach commented out, then iterative DP with full array, then space-optimized to three variables

### Related Reasoning
- [[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]: both show [[dp_translation_friction]] and [[state_variable_minimization]] with shared [[wrong_path]]
- [[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]: both show [[dp_translation_friction]] and [[state_variable_minimization]] with shared [[wrong_path]]
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: both show [[dp_translation_friction]] and [[state_variable_minimization]]
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]: both show [[dp_translation_friction]] with shared [[wrong_path]]

### Signals
- Commented-out recursive solution says it will give `TLE` as `O(2^n)` without caching
- Commented-out intermediate: 'easier to understand' array-based DP before space optimization
