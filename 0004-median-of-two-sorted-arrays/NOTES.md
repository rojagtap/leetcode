---
problem_id: '0004'
platform: 'leetcode'
title: 'Median of Two Sorted Arrays'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0004-median-of-two-sorted-arrays'
primary_tags:
  - '[[binary-search]]'
subtle_tags:
  - '[[binary_search_on_answer_space]]'
  - '[[boundary_as_information_carrier]]'
candidate_tags: []
mistakes:
  - '[[proof_gap]]'
related:
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]'
  - '[[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]'
  - '[[leetcode/0128-longest-consecutive-sequence/NOTES|0128-longest-consecutive-sequence]]'
  - '[[leetcode/0130-surrounded-regions/NOTES|0130-surrounded-regions]]'
---

## Explanations

The extended comment suggests the solver needed to convince themselves that checking only boundary elements suffices to validate the partition. The insight that the search is over partition positions (not element values) is the core binary-search-on-answer-space move, and the boundary cross-check is the proof obligation that likely caused friction.

### Subtle Tags
- [[binary_search_on_answer_space]]: recognizing that the answer itself is monotone and searchable rather than searching the input directly
- [[boundary_as_information_carrier]]: recognizing that iterating from a boundary (edge of array, border of grid, start/end) provides privileged information that eliminates redundant computation

### Mistake Notes
- [[proof_gap]]: lengthy comment works through why partition correctness reduces to cross-boundary comparisons

### Related Reasoning
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both show [[boundary_as_information_carrier]] with shared [[proof_gap]]
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0073-set-matrix-zeroes/NOTES|0073-set-matrix-zeroes]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0128-longest-consecutive-sequence/NOTES|0128-longest-consecutive-sequence]]: both show [[boundary_as_information_carrier]]
- [[leetcode/0130-surrounded-regions/NOTES|0130-surrounded-regions]]: both show [[boundary_as_information_carrier]]

### Signals
- comment: we are not concerned with all the `n/2` elements, just the max 1 or 2 (in case of even)
- comment: to confirm if this is the true left side, we just need to make sure that `left1[-1] < right2[0]` and `left2[-1] < right1[0]`
