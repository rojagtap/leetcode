---
problem_id: '0994'
platform: 'leetcode'
title: 'Rotting Oranges'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0994-rotting-oranges'
primary_tags:
  - '[[graph-bfs]]'
  - '[[matrix]]'
subtle_tags:
  - '[[boundary_as_information_carrier]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]'
  - '[[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]'
  - '[[leetcode/0128-longest-consecutive-sequence/NOTES|0128-longest-consecutive-sequence]]'
---

## Explanations

The solver's comment describes the multi-source BFS approach clearly. The use of `time = -1` with pre-increment suggests awareness of the off-by-one subtlety in level counting. No wrong paths or struggle visible.

### Subtle Tags
- [[boundary_as_information_carrier]]: recognizing that iterating from a boundary (edge of array, border of grid, start/end) provides privileged information that eliminates redundant computation

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0128-longest-consecutive-sequence/NOTES|0128-longest-consecutive-sequence]]: both show [[boundary_as_information_carrier]]

### Signals
- comment 'initially the level is the existing rotten oranges' indicates the solver recognized multi-source BFS seeding from boundary conditions
