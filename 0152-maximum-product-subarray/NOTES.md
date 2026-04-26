---
problem_id: '0152'
platform: 'leetcode'
title: 'Maximum Product Subarray'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0152-maximum-product-subarray'
primary_tags:
  - '[[dp]]'
subtle_tags:
  - '[[negation_dual_tracking]]'
  - '[[counterexample_disproof_pivot]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]'
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
  - '[[leetcode/0055-jump-game/NOTES|0055-jump-game]]'
  - '[[leetcode/0337-house-robber-iii/NOTES|0337-house-robber-iii]]'
  - '[[leetcode/0746-min-cost-climbing-stairs/NOTES|0746-min-cost-climbing-stairs]]'
---

## Explanations

The solver explicitly constructed a counterexample to disprove the single-running-product approach: negatives that cancel each other are lost when the running product is reset. The fix is tracking both min and max simultaneously, since a large negative product can become the max after another negation.

### Subtle Tags
- [[negation_dual_tracking]]: when negation or inversion can flip min to max (or break monotonicity), tracking both min and max simultaneously recovers correctness
- [[counterexample_disproof_pivot]]: solver proposes an approach, then constructs or recalls a specific counter-example to disprove it, using the failure to pivot to the correct approach

### Mistake Notes
- [[wrong_path]]: First attempt used single running product with `max(nums[i], runningprod)` reset, then constructed counterexample `[2,3,-2,-4]` showing double negatives cancel -- pivoted to dual min/max tracking

### Related Reasoning
- [[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0055-jump-game/NOTES|0055-jump-game]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0337-house-robber-iii/NOTES|0337-house-robber-iii]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0746-min-cost-climbing-stairs/NOTES|0746-min-cost-climbing-stairs]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]

### Signals
- Comment: but there is a problem here; for `nums = [2,3,-2,-4]` the above solution fails
- Comment: instead, we can keep a `runningmax` and `runningmin` (i.e. on a single negative value, `runningmax` becomes the min)
- Explicit counterexample construction: `runningprod = 2, 6, -2, 8`; the above approach will output 8, but the actual answer should be 48
