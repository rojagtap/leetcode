---
problem_id: '0309'
platform: 'leetcode'
title: 'Best Time to Buy and Sell Stock with Cooldown'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0309-best-time-to-buy-and-sell-stock-with-cooldown'
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
  - '[[leetcode/0198-house-robber/NOTES|0198-house-robber]]'
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
  - '[[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]'
---

## Explanations

The solver clearly struggled with what to memoize. The comment about passing profit through the recursion -- then realizing it breaks cacheability -- is a textbook state_variable_minimization insight: profit is derivable from the subproblem return value, not an independent state dimension. The four retained implementations (brute force through space-optimized) with the commented "easier to read" variant suggest the bottom-up translation and variable compression also caused friction.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error
- [[state_variable_minimization]]: realizing a state variable in the recurrence is redundant because it's derivable from others, reducing dimensionality of the DP

### Mistake Notes
- [[wrong_path]]: initially tried passing current profit through recursion, which breaks memoization because profit does not repeat for same (state, index)

### Related Reasoning
- [[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]: both show [[dp_translation_friction]] and [[state_variable_minimization]] with shared [[wrong_path]]
- [[leetcode/0198-house-robber/NOTES|0198-house-robber]]: both show [[dp_translation_friction]] and [[state_variable_minimization]] with shared [[wrong_path]]
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: both show [[dp_translation_friction]] and [[state_variable_minimization]]
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]: both show [[dp_translation_friction]] with shared [[wrong_path]]

### Signals
- 'it is a very obvious choice to also send the current profit and pass on -price + profit for buy and price + profit for sell'
- 'however, this doesn't work as this does not repeat. i.e., the same profit for a given buy/sell choice for an index won't repeat'
- Four progressively optimized implementations: `naive backtracking -> memo -> bottom-up -> space-optimized`
- Commented-out 'easier to read' version of the space-optimized loop
