---
problem_id: '0337'
platform: 'leetcode'
title: 'House Robber III'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0337-house-robber-iii'
primary_tags:
  - '[[dp]]'
  - '[[binary-tree]]'
  - '[[memoization]]'
subtle_tags:
  - '[[counterexample_disproof_pivot]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]'
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
  - '[[leetcode/0055-jump-game/NOTES|0055-jump-game]]'
  - '[[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]'
  - '[[leetcode/0746-min-cost-climbing-stairs/NOTES|0746-min-cost-climbing-stairs]]'
---

## Explanations

The solver first tried flattening the tree into levels and applying the linear house-robber recurrence, which fails because nodes at the same level are not necessarily all-or-nothing choices (a node's grandchildren can be on the same level as its sibling's children). The ASCII-art counterexample in the commented-out code shows the exact case that disproved the approach, prompting the pivot to per-node memoized recursion.

### Subtle Tags
- [[counterexample_disproof_pivot]]: solver proposes an approach, then constructs or recalls a specific counter-example to disprove it, using the failure to pivot to the correct approach

### Mistake Notes
- [[wrong_path]]: initially tried level-order traversal with linear house-robber DP, then found a counterexample tree that disproves it

### Related Reasoning
- [[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0055-jump-game/NOTES|0055-jump-game]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0746-min-cost-climbing-stairs/NOTES|0746-min-cost-climbing-stairs]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]

### Signals
- `level order traversal + max[i] = max(max[i - 1], nums[i] + max[i - 2]) does not work`
- Commented-out wrong solution with explicit counterexample: tree `[3,[2,[3]],[4]]` where the answer is `3 + 4 = 7`
- `doesnt work for` followed by an ASCII-drawn tree
