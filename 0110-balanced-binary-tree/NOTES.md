---
problem_id: '0110'
platform: 'leetcode'
title: 'Balanced Binary Tree'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '0110-balanced-binary-tree'
primary_tags:
  - '[[binary-tree]]'
subtle_tags:
  - '[[state_variable_minimization]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]'
  - '[[leetcode/0198-house-robber/NOTES|0198-house-robber]]'
  - '[[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]'
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
---

## Explanations

The solver likely first wrote the straightforward approach with separate height calls and a memoization cache, then realized the height could be threaded as a single reference parameter through the recursion, eliminating the need for the map entirely. This is a state-variable reduction -- the height is computed in the same pass as the balance check.

### Subtle Tags
- [[state_variable_minimization]]: realizing a state variable in the recurrence is redundant because it's derivable from others, reducing dimensionality of the DP

### Mistake Notes
- [[wrong_path]]: First approach computed height separately with a cache map, then rewrote to thread height as a reference parameter to avoid redundant computation

### Related Reasoning
- [[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]: both show [[state_variable_minimization]] with shared [[wrong_path]]
- [[leetcode/0198-house-robber/NOTES|0198-house-robber]]: both show [[state_variable_minimization]] with shared [[wrong_path]]
- [[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]: both show [[state_variable_minimization]] with shared [[wrong_path]]
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: both show [[state_variable_minimization]]

### Signals
- Commented-out first solution uses `unordered_map<TreeNode*, int> cache` and a separate `get_height` function
- Active solution comment: `keep send pointer to height down the tree and update it at the end / this way we dont have to re calculate or cache heights`
