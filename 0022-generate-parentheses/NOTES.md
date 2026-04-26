---
problem_id: '0022'
platform: 'leetcode'
title: 'Generate Parentheses'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0022-generate-parentheses'
primary_tags:
  - '[[backtracking]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[proof_gap]]'
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]'
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0051-n-queens/NOTES|0051-n-queens]]'
  - '[[leetcode/0124-binary-tree-maximum-path-sum/NOTES|0124-binary-tree-maximum-path-sum]]'
---

## Explanations

The solver added a memoization cache keyed on `(current_string, openCount, closeCount)`, but the recursive structure never revisits the same `(string, open, close)` triple -- each path produces a unique prefix. The cache appears to be a defensive addition, suggesting uncertainty about whether the backtracking could revisit states. This is a proof_gap: the code is correct but carries unnecessary machinery.

### Mistake Notes
- [[proof_gap]]: memoization cache on `(string, openCount, closeCount)` is redundant -- the recursion tree has no overlapping states given how `open` and `close` counts advance

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: shared [[proof_gap]] pattern
- [[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]: shared [[proof_gap]] pattern
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: shared [[proof_gap]] pattern
- [[leetcode/0051-n-queens/NOTES|0051-n-queens]]: shared [[proof_gap]] pattern
- [[leetcode/0124-binary-tree-maximum-path-sum/NOTES|0124-binary-tree-maximum-path-sum]]: shared [[proof_gap]] pattern

### Signals
- tuple-based cache set used despite the recursion tree being a strict tree with no reconvergence
