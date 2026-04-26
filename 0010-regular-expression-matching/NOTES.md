---
problem_id: '0010'
platform: 'leetcode'
title: 'Regular Expression Matching'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0010-regular-expression-matching'
primary_tags:
  - '[[dp]]'
  - '[[backtracking]]'
  - '[[memoization]]'
subtle_tags:
  - '[[dp_translation_friction]]'
  - '[[state_variable_minimization]]'
candidate_tags: []
mistakes:
  - '[[representation_shift]]'
related:
  - '[[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]'
  - '[[leetcode/0198-house-robber/NOTES|0198-house-robber]]'
  - '[[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]'
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
  - '[[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]'
---

## Explanations

The file preserves the full progression from brute-force backtracking through memoization, bottom-up DP, and finally space-optimized DP. This strongly suggests dp_translation_friction -- the solver walked through each transformation step deliberately. The comment `why not just keep that instead of entire m * n array` marks the space-optimization insight as a separate realization, and the state_variable_minimization tag fits the row-reduction step.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error
- [[state_variable_minimization]]: realizing a state variable in the recurrence is redundant because it's derivable from others, reducing dimensionality of the DP

### Mistake Notes
- [[representation_shift]]: four complete implementations kept: `brute backtracking -> memo -> bottom-up -> space-optimized`

### Related Reasoning
- [[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]: both show [[dp_translation_friction]] and [[state_variable_minimization]]
- [[leetcode/0198-house-robber/NOTES|0198-house-robber]]: both show [[dp_translation_friction]] and [[state_variable_minimization]]
- [[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]: both show [[dp_translation_friction]] and [[state_variable_minimization]]
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[dp_translation_friction]]
- [[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]: both show [[dp_translation_friction]]

### Signals
- comment: `optimized bottom-up... we only need current and next row`
- comment: `why not just keep that instead of entire m * n array`
- four versions of the solution are preserved (`brute`, `memo`, `bottom-up`, `space-optimized`)
