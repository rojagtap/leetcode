---
problem_id: '0054'
platform: 'leetcode'
title: 'Spiral Matrix'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0054-spiral-matrix'
primary_tags:
  - '[[matrix]]'
subtle_tags:
  - '[[boundary_as_information_carrier]]'
candidate_tags: []
mistakes:
  - '[[micro_hesitation]]'
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]'
  - '[[leetcode/0128-longest-consecutive-sequence/NOTES|0128-longest-consecutive-sequence]]'
  - '[[leetcode/0130-surrounded-regions/NOTES|0130-surrounded-regions]]'
---

## Explanations

The solver chose recursion over the boundary-shrinking iterative approach but encountered subtlety in the direction-switching condition. The comment about removing the first condition and testing with a specific matrix suggests the top-to-right transition guard was found through a counterexample rather than derived from the invariant. The boundary-shrinking alternative mentioned in comments appears to have been considered but not pursued.

### Subtle Tags
- [[boundary_as_information_carrier]]: recognizing that iterating from a boundary (edge of array, border of grid, start/end) provides privileged information that eliminates redundant computation

### Mistake Notes
- [[micro_hesitation]]: comment notes 'for first condition try removing it' with a specific test case, suggesting the direction-switch guard was debugged empirically

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0128-longest-consecutive-sequence/NOTES|0128-longest-consecutive-sequence]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0130-surrounded-regions/NOTES|0130-surrounded-regions]]: both show [[boundary_as_information_carrier]]

### Signals
- `cleaner way would be recursion`
- `for first condition try removing it and take matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]`
- `iterative is also possible the idea is take right, down, left, and top boundaries and go on shrinking them`
