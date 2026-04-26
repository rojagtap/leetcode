---
problem_id: '0031'
platform: 'leetcode'
title: 'Next Permutation'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0031-next-permutation'
primary_tags:
  - '[[sorting]]'
subtle_tags:
  - '[[counterexample_disproof_pivot]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
  - '[[proof_gap]]'
related:
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
  - '[[leetcode/0055-jump-game/NOTES|0055-jump-game]]'
  - '[[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]'
  - '[[leetcode/0337-house-robber-iii/NOTES|0337-house-robber-iii]]'
  - '[[leetcode/0746-min-cost-climbing-stairs/NOTES|0746-min-cost-climbing-stairs]]'
---

## Explanations

The solver explicitly rejects brute-force enumeration, then reasons through progressively harder examples to discover the pivot-and-reverse algorithm. The comment `we cannot do anymore swapping` and the worked example of `[1,5,3,2]` suggest the solver used concrete counterexamples to disprove local swapping before arriving at the suffix-descent invariant. The lengthy derivation indicates the correctness proof -- particularly why the suffix must be descending -- required deliberate construction.

### Subtle Tags
- [[counterexample_disproof_pivot]]: solver proposes an approach, then constructs or recalls a specific counter-example to disprove it, using the failure to pivot to the correct approach

### Mistake Notes
- [[wrong_path]]: comment explicitly considers and dismisses brute-force `O(n * n!)` permutation generation
- [[proof_gap]]: extended comment works through multiple examples to justify why the suffix is always descending after finding the pivot

### Related Reasoning
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0055-jump-game/NOTES|0055-jump-game]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0337-house-robber-iii/NOTES|0337-house-robber-iii]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0746-min-cost-climbing-stairs/NOTES|0746-min-cost-climbing-stairs]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]

### Signals
- comment: `the bruteforce approach here is to generate all the permutations... need a better approach`
- comment: `we cannot do anymore swapping with units and tens places as this will bring down to the smaller number`
- comment: `as long as the ith place number is >= (i + 1)st place, swapping cannot happen`
- comment traces three examples: `[1,5,2,3]`, `[1,5,3,2]`, `[2,1,5,4,3,0,0]`
