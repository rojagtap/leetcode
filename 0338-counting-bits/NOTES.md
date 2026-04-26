---
problem_id: '0338'
platform: 'leetcode'
title: 'Counting Bits'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '0338-counting-bits'
primary_tags:
  - '[[dp]]'
  - '[[bit-manipulation]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The solver built the recurrence by inspecting the binary patterns of consecutive numbers, observing that the bit count of `x` depends on `x / 2` plus the LSB. The detailed binary listing suggests the pattern was derived empirically rather than recalled.

### Signals
- Comment traces binary representations of 0-15 to derive the recurrence visually
