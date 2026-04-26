---
problem_id: '0283'
platform: 'leetcode'
title: 'Move Zeroes'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '0283-move-zeroes'
primary_tags:
  - '[[two-pointer]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[micro_hesitation]]'
related:
  - '[[leetcode/0007-reverse-integer/NOTES|0007-reverse-integer]]'
  - '[[leetcode/0048-rotate-image/NOTES|0048-rotate-image]]'
  - '[[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]'
  - '[[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]'
  - '[[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]'
---

## Explanations

The comment hints that the solver likely first tried having r start from 0 or some other position, causing the zero-placement logic to be more complex. Starting r from l simplifies the invariant that the swap target always advances.

### Mistake Notes
- [[micro_hesitation]]: comment 'it is easier if r starts from l' suggests an earlier attempt where r started independently

### Related Reasoning
- [[leetcode/0007-reverse-integer/NOTES|0007-reverse-integer]]: shared [[micro_hesitation]] pattern
- [[leetcode/0048-rotate-image/NOTES|0048-rotate-image]]: shared [[micro_hesitation]] pattern
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: shared [[micro_hesitation]] pattern
- [[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]: shared [[micro_hesitation]] pattern
- [[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]: shared [[micro_hesitation]] pattern

### Signals
- 'it is easier if r starts from l that way the 0 always moves forward'
