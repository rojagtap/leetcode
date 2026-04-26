---
problem_id: '2139'
platform: 'leetcode'
title: 'Detect Squares'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '2139-detect-squares'
primary_tags:
  - '[[hashmap]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

Clean implementation. The comment about duplicate point multiplication suggests the solver recognized the combinatorial counting subtlety, but no wrong path or significant friction is visible.

### Signals
- comment 'diagx - x == diagy - y' states the square diagonal constraint
- inline comment '* because there can be duplicate entries of points' notes the multiplicative counting for duplicates
