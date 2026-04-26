---
problem_id: '0678'
platform: 'leetcode'
title: 'Valid Parenthesis String'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0678-valid-parenthesis-string'
primary_tags:
  - '[[greedy]]'
subtle_tags:
  - '[[negation_dual_tracking]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]'
  - '[[leetcode/3900-longest-balanced-substring-after-one-swap/NOTES|3900-longest-balanced-substring-after-one-swap]]'
---

## Explanations

The solver first describes the exponential DP approach (branching on each `*` as open/close/empty), then pivots to the two-pass greedy where `*` is treated optimistically in each direction. Tracking forward and backward counts simultaneously -- where one pass assumes `*` is `(` and the other assumes `*` is `)` -- is a form of dual tracking that covers both failure modes in a single linear scan.

### Subtle Tags
- [[negation_dual_tracking]]: when negation or inversion can flip min to max (or break monotonicity), tracking both min and max simultaneously recovers correctness

### Related Reasoning
- [[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]: both show [[negation_dual_tracking]]
- [[leetcode/3900-longest-balanced-substring-after-one-swap/NOTES|3900-longest-balanced-substring-after-one-swap]]: both show [[negation_dual_tracking]]

### Signals
- Comment describes the brute-force DP tree before pivoting to the two-pass greedy
- `iterate from left to right first and take * as ( ... next, iterate in the opposite direction with * as )`
- `we allow values of open >= 0 (> because _ is also an option which can lead to extra (s in our iteration)`
