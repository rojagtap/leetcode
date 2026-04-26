---
problem_id: '0073'
platform: 'leetcode'
title: 'Set Matrix Zeroes'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0073-set-matrix-zeroes'
primary_tags:
  - '[[matrix]]'
subtle_tags:
  - '[[boundary_as_information_carrier]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]'
  - '[[leetcode/0128-longest-consecutive-sequence/NOTES|0128-longest-consecutive-sequence]]'
  - '[[leetcode/0130-surrounded-regions/NOTES|0130-surrounded-regions]]'
---

## Explanations

The solver recognized that the first row and first column can serve as in-place markers, eliminating the need for auxiliary storage. The comment about the `firstcol` flag shows awareness that the `0th` column's own zero status would be ambiguous once it is overloaded as a marker -- a classic boundary-as-information-carrier subtlety.

### Subtle Tags
- [[boundary_as_information_carrier]]: recognizing that iterating from a boundary (edge of array, border of grid, start/end) provides privileged information that eliminates redundant computation

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0128-longest-consecutive-sequence/NOTES|0128-longest-consecutive-sequence]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0130-surrounded-regions/NOTES|0130-surrounded-regions]]: both show [[boundary_as_information_carrier]]

### Signals
- use a `set`, `O(m + n)` space
- for `O(1)` space, if any cell is `0`, set `(i, 0)` and `(0, j)` for that cell to `0`
- `to identify if the 0th col is actually 0 and doesnt just have other cell's 0s, keep a flag`
