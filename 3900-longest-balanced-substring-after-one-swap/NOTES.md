---
problem_id: '3900'
platform: 'leetcode'
title: 'Longest Balanced Substring After One Swap'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '3900-longest-balanced-substring-after-one-swap'
primary_tags:
  - '[[prefix-sum]]'
  - '[[hashmap]]'
subtle_tags:
  - '[[prefix_suffix_decomposition]]'
  - '[[negation_dual_tracking]]'
candidate_tags: []
mistakes:
  - '[[proof_gap]]'
related:
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0121-best-time-to-buy-and-sell-stock/NOTES|0121-best-time-to-buy-and-sell-stock]]'
  - '[[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]'
  - '[[leetcode/0238-product-of-array-except-self/NOTES|0238-product-of-array-except-self]]'
  - '[[leetcode/0678-valid-parenthesis-string/NOTES|0678-valid-parenthesis-string]]'
---

## Explanations

The solver appears to have built the solution incrementally, adding conditions as edge cases surfaced. The comments explaining why both the outer-availability check and the earliest-with-character lookup are needed ("this itself is not enough") suggest the correctness proof was assembled piece by piece rather than derived from a single clean invariant. The prefix_suffix_decomposition and negation_dual_tracking (tracking both 0-surplus and 1-surplus cases symmetrically) are central to the approach.

### Subtle Tags
- [[prefix_suffix_decomposition]]: decomposing a problem into prefix and suffix passes, where each pass carries cumulative information the other needs
- [[negation_dual_tracking]]: when negation or inversion can flip min to max (or break monotonicity), tracking both min and max simultaneously recovers correctness

### Mistake Notes
- [[proof_gap]]: inline comments explain the +/-2 logic and the need for both outer-character checks and earliest-with-character lookups, suggesting the correctness argument was built incrementally

### Related Reasoning
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both show [[prefix_suffix_decomposition]] with shared [[proof_gap]]
- [[leetcode/0121-best-time-to-buy-and-sell-stock/NOTES|0121-best-time-to-buy-and-sell-stock]]: both show [[prefix_suffix_decomposition]]
- [[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]: both show [[negation_dual_tracking]]
- [[leetcode/0238-product-of-array-except-self/NOTES|0238-product-of-array-except-self]]: both show [[prefix_suffix_decomposition]]
- [[leetcode/0678-valid-parenthesis-string/NOTES|0678-valid-parenthesis-string]]: both show [[negation_dual_tracking]]

### Signals
- comment '+-2 because the length of the substring needs to be even'
- comment 'we want substring diff -2 (substring has too many 0s) so curr - prev = -2 => prev = curr + 2' -- algebraic reasoning written inline
- comment 'this checks for prefix + 2 with at least one one to the left' followed by 'this itself is not enough because we also need to check for the case where there is no one at the left but at least one in the right, hence the if above'
- three separate lookup maps (lookup_earliest, lookup_earliest_0, lookup_earliest_1) suggest the solver needed multiple refinements to handle all swap-source cases
