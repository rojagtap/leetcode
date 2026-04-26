---
problem_id: '0268'
platform: 'leetcode'
title: 'Missing Number'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '0268-missing-number'
primary_tags:
  - '[[bit-manipulation]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The solver implemented both the arithmetic and XOR approaches, keeping both in the file. The comment calling the math approach "obvious" and then pivoting to XOR suggests the solver was deliberate about exploring the bit-manipulation alternative, likely as practice rather than from friction.

### Signals
- Both math and XOR solutions are present; the math approach is commented out, suggesting the solver explored both and chose XOR
- `the obvious solution is (n * (n + 1) / 2) - sum(nums) but we can also do bit manipulation`
