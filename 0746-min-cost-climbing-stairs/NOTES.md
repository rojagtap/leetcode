---
problem_id: '0746'
platform: 'leetcode'
title: 'Min Cost Climbing Stairs'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '0746-min-cost-climbing-stairs'
primary_tags:
  - '[[dp]]'
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
  - '[[leetcode/0337-house-robber-iii/NOTES|0337-house-robber-iii]]'
---

## Explanations

The solver first tried a greedy approach of always picking the cheaper of the next two steps, which works on some inputs but fails on `[10,15,20]`. The explicit counterexample in the comments shows the greedy picks `10` then is forced into `15`, totaling `25`, while the optimal is just `15` (skip to index `1`, then jump to the top). This disproof pivoted the solver to the DP recurrence.

### Subtle Tags
- [[counterexample_disproof_pivot]]: solver proposes an approach, then constructs or recalls a specific counter-example to disprove it, using the failure to pivot to the correct approach

### Mistake Notes
- [[wrong_path]]: initially tried greedy (always pick min of next two), found counterexample `[10,15,20]` where greedy picks `10 + 15` instead of the optimal `15`

### Related Reasoning
- [[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0055-jump-game/NOTES|0055-jump-game]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0337-house-robber-iii/NOTES|0337-house-robber-iii]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]

### Signals
- Comment traces greedy on `[1,100,1,1,1,100,1,1,100,1]` then shows `but for cost = [10,15,20] greedy wont work`
