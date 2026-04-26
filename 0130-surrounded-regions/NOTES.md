---
problem_id: '0130'
platform: 'leetcode'
title: 'Surrounded Regions'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0130-surrounded-regions'
primary_tags:
  - '[[graph-dfs]]'
  - '[[matrix]]'
subtle_tags:
  - '[[boundary_as_information_carrier]]'
  - '[[retain_vs_remove_reframing]]'
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

The solver recognized the retain-vs-remove reframing: instead of detecting which Os are surrounded (hard), mark which Os are safe by starting DFS from borders (easy). The boundary provides privileged information -- any O reachable from an edge is inherently unsurrounded.

### Subtle Tags
- [[boundary_as_information_carrier]]: recognizing that iterating from a boundary (edge of array, border of grid, start/end) provides privileged information that eliminates redundant computation
- [[retain_vs_remove_reframing]]: switching between "process and remove" to "retain until last" changes subproblem structure from dependent to independent

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0128-longest-consecutive-sequence/NOTES|0128-longest-consecutive-sequence]]: both show [[boundary_as_information_carrier]]

### Signals
- Comment: 'all the Os that are not surrounded by Xs will ALWAYS be connected to a O which is at the border'
- Strategy: mark border-connected Os as 'N', then capture remaining Os, then restore Ns
