---
problem_id: '0322'
platform: 'leetcode'
title: 'Coin Change'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0322-coin-change'
primary_tags:
  - '[[dp]]'
subtle_tags:
  - '[[dp_translation_friction]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
  - '[[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]'
  - '[[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]'
  - '[[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]'
---

## Explanations

The solver flags the recurrence as `a bit tricky`, then builds intuition through a manual trace of `amount = 1` through `amount = 11` before writing the formula. Keeping both top-down and bottom-up suggests the translation between forms was practiced deliberately.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error

### Related Reasoning
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: both show [[dp_translation_friction]]
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[dp_translation_friction]]
- [[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]: both show [[dp_translation_friction]]
- [[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]: both show [[dp_translation_friction]]
- [[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]: both show [[dp_translation_friction]]

### Signals
- Comment traces the recurrence through a full worked example before stating the formula
- `the recurrence relation here is a bit tricky`
- Both top-down and bottom-up implementations retained
