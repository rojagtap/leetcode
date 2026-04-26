---
problem_id: '0042'
platform: 'leetcode'
title: 'Trapping Rain Water'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0042-trapping-rain-water'
primary_tags:
  - '[[two-pointer]]'
  - '[[prefix-sum]]'
subtle_tags:
  - '[[prefix_suffix_decomposition]]'
  - '[[boundary_as_information_carrier]]'
candidate_tags: []
mistakes:
  - '[[proof_gap]]'
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/3900-longest-balanced-substring-after-one-swap/NOTES|3900-longest-balanced-substring-after-one-swap]]'
  - '[[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]'
  - '[[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]'
  - '[[leetcode/0121-best-time-to-buy-and-sell-stock/NOTES|0121-best-time-to-buy-and-sell-stock]]'
---

## Explanations

The solver first describes the prefix-array approach (`maxLeft[]` and `maxRight[]`) and then optimizes to the two-pointer `O(1)`-space version. The lengthy justification for why the "true" max on the opposite side does not matter suggests the proof that the two-pointer invariant preserves correctness was the main friction point. The reference to an external video reinforces that this proof was not self-evident during the solve.

### Subtle Tags
- [[prefix_suffix_decomposition]]: decomposing a problem into prefix and suffix passes, where each pass carries cumulative information the other needs
- [[boundary_as_information_carrier]]: recognizing that iterating from a boundary (edge of array, border of grid, start/end) provides privileged information that eliminates redundant computation

### Mistake Notes
- [[proof_gap]]: extended comment works through why the 'true' maxRight is irrelevant when maxLeft is the binding constraint

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both show [[boundary_as_information_carrier]] with shared [[proof_gap]]
- [[leetcode/3900-longest-balanced-substring-after-one-swap/NOTES|3900-longest-balanced-substring-after-one-swap]]: both show [[prefix_suffix_decomposition]] with shared [[proof_gap]]
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0121-best-time-to-buy-and-sell-stock/NOTES|0121-best-time-to-buy-and-sell-stock]]: both show [[prefix_suffix_decomposition]]

### Signals
- comment: in reality, the true `maxRight` for position 3 is 3 (from observation); however, we are not concerned with the high values of right
- comment: we are not concerned with the true `maxLeft` for position 8 as long as `maxRight` is the true `maxRight` for position 8
- comment references external video explanation: see https://www.youtube.com/watch?v=ZI2z5pq0TqA
- comment describes `O(n)`-space prefix-array approach before optimizing to `O(1)` two-pointer
