---
problem_id: '0019'
platform: 'leetcode'
title: 'Remove Nth Node From End of List'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0019-remove-nth-node-from-end-of-list'
primary_tags:
  - '[[two-pointer]]'
  - '[[linked-list]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[representation_shift]]'
related:
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
  - '[[leetcode/0017-letter-combinations-of-a-phone-number/NOTES|0017-letter-combinations-of-a-phone-number]]'
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
  - '[[leetcode/0046-permutations/NOTES|0046-permutations]]'
  - '[[leetcode/0078-subsets/NOTES|0078-subsets]]'
---

## Explanations

The comment about eliminating the `prev` pointer by spacing `slow` and `fast` `n + 1` apart suggests a micro-optimization insight that came after the initial implementation. The two-pass approach is kept as a commented-out alternative, indicating the solver progressed from a straightforward size-counting method to the one-pass trick.

### Mistake Notes
- [[representation_shift]]: two-pass size-counting approach commented out in favor of one-pass slow/fast pointer

### Related Reasoning
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: shared [[representation_shift]] pattern
- [[leetcode/0017-letter-combinations-of-a-phone-number/NOTES|0017-letter-combinations-of-a-phone-number]]: shared [[representation_shift]] pattern
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: shared [[representation_shift]] pattern
- [[leetcode/0046-permutations/NOTES|0046-permutations]]: shared [[representation_shift]] pattern
- [[leetcode/0078-subsets/NOTES|0078-subsets]]: shared [[representation_shift]] pattern

### Signals
- comment: `prev is not required if slow and fast are n + 1 spaces apart`
- two-pass approach preserved as commented-out code
