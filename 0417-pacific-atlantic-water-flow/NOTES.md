---
problem_id: '0417'
platform: 'leetcode'
title: 'Pacific Atlantic Water Flow'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0417-pacific-atlantic-water-flow'
primary_tags:
  - '[[graph-dfs]]'
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

The solver recognizes that starting DFS from the ocean borders (going uphill) is more efficient than checking every internal cell's reachability to both oceans. This boundary-first traversal is the core insight: borders carry privileged information about ocean connectivity, eliminating redundant per-cell searches.

### Subtle Tags
- [[boundary_as_information_carrier]]: recognizing that iterating from a boundary (edge of array, border of grid, start/end) provides privileged information that eliminates redundant computation

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0128-longest-consecutive-sequence/NOTES|0128-longest-consecutive-sequence]]: both show [[boundary_as_information_carrier]]

### Signals
- 'all the internal cells HAVE TO pass through the border cells to enter the ocean so start dfs from borders and go reverse'
