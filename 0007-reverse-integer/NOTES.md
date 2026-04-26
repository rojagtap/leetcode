---
problem_id: '0007'
platform: 'leetcode'
title: 'Reverse Integer'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0007-reverse-integer'
primary_tags:
  - '[[math]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[micro_hesitation]]'
related:
  - '[[leetcode/0048-rotate-image/NOTES|0048-rotate-image]]'
  - '[[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]'
  - '[[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]'
---

## Explanations

The solver appears to have manually traced the digit-by-digit reversal to understand at which step overflow can occur. The step-by-step table in the comment suggests the overflow guard condition was not immediately obvious and required working through a concrete near-overflow example.

### Mistake Notes
- [[micro_hesitation]]: comment manually traces reversal of 1463847412 step by step to derive the overflow boundary condition

### Related Reasoning
- [[leetcode/0048-rotate-image/NOTES|0048-rotate-image]]: both spell out low-level state updates step by step, so the shared issue is [[micro_hesitation]] around index or arithmetic bookkeeping rather than the main idea
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: both over-explain small coordinate transitions, which suggests the friction sits in boundary arithmetic and loop mechanics, a shared [[micro_hesitation]]
- [[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]: both expand concrete examples to settle a local transition rule that should eventually become fluent, so the common issue is [[micro_hesitation]]

### Signals
- comment traces `r` and `x` values step by step to show how reversal approaches `INT_MAX`
- comment: `INT_MAX = 2147483647 and INT_MIN = -2147483648`
