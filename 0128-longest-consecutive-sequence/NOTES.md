---
problem_id: '0128'
platform: 'leetcode'
title: 'Longest Consecutive Sequence'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0128-longest-consecutive-sequence'
primary_tags:
  - '[[hashmap]]'
subtle_tags:
  - '[[boundary_as_information_carrier]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]'
  - '[[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]'
  - '[[leetcode/0130-surrounded-regions/NOTES|0130-surrounded-regions]]'
---

## Explanations

The solver likely first tried materializing the full numeric range as a boolean array, which fails on sparse inputs. The key insight in the working solution is that only sequence-start elements (those without num-1 in the set) need to be expanded -- this boundary check eliminates redundant scans.

### Subtle Tags
- [[boundary_as_information_carrier]]: recognizing that iterating from a boundary (edge of array, border of grid, start/end) provides privileged information that eliminates redundant computation

### Mistake Notes
- [[wrong_path]]: First approach used a boolean range vector from min to max -- gives `TLE` on sparse ranges

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0130-surrounded-regions/NOTES|0130-surrounded-regions]]: both show [[boundary_as_information_carrier]]

### Signals
- Commented-out solution: `create a range boolean vector from the smallest to the largest element / Gives TLE`
- Active solution comment: 'if num - 1 does not exist in the set, it means that a sequence starts from this number'
