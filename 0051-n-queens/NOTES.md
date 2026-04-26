---
problem_id: '0051'
platform: 'leetcode'
title: 'N-Queens'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0051-n-queens'
primary_tags:
  - '[[backtracking]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[proof_gap]]'
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/0022-generate-parentheses/NOTES|0022-generate-parentheses]]'
  - '[[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]'
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0124-binary-tree-maximum-path-sum/NOTES|0124-binary-tree-maximum-path-sum]]'
---

## Explanations

The comment about needing to start at `row > 0` and the modular next-row `(i + 1) % n` suggests some uncertainty about whether sequential row placement covers all solutions. In the standard N-Queens formulation, placing one queen per row starting from row `0` is sufficient and the modular wrap is not needed, indicating a likely proof gap about why row-sequential placement is exhaustive.

### Mistake Notes
- [[proof_gap]]: comment mentions `we might need to start at row > 0` and uses modular arithmetic for the next row, which is unnecessary for the standard row-by-row approach

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: shared [[proof_gap]] pattern
- [[leetcode/0022-generate-parentheses/NOTES|0022-generate-parentheses]]: shared [[proof_gap]] pattern
- [[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]: shared [[proof_gap]] pattern
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: shared [[proof_gap]] pattern
- [[leetcode/0124-binary-tree-maximum-path-sum/NOTES|0124-binary-tree-maximum-path-sum]]: shared [[proof_gap]] pattern

### Signals
- `note that since we want all solutions we might need to start at row > 0`
- `so the next row needs to be (row + 1) % n`
