---
problem_id: '0050'
platform: 'leetcode'
title: 'Pow(x, n)'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0050-powx-n'
primary_tags:
  - '[[divide-and-conquer]]'
  - '[[bit-manipulation]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related: []
---

## Explanations

The solver first implemented the naive linear-time multiply/divide loop, then recognized the exponentiation-by-squaring pattern. The commented-out naive approach and the explicit numerical example in comments suggest the squaring optimization was not the first instinct.

### Mistake Notes
- [[wrong_path]]: initial linear approach (multiply/divide in loop) replaced by exponentiation by squaring

### Signals
- `a more optimized approach is to do exponentiation by squaring`
- `instead of doing x *= 2 for i = 8, 7, 6, 5, ..., 0, we can x *= x for i = 8, 4, 2, 1`
- commented-out linear `O(n)` approach preserved
