---
problem_id: '0046'
platform: 'leetcode'
title: 'Permutations'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0046-permutations'
primary_tags:
  - '[[backtracking]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[representation_shift]]'
related:
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
  - '[[leetcode/0017-letter-combinations-of-a-phone-number/NOTES|0017-letter-combinations-of-a-phone-number]]'
  - '[[leetcode/0019-remove-nth-node-from-end-of-list/NOTES|0019-remove-nth-node-from-end-of-list]]'
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
  - '[[leetcode/0078-subsets/NOTES|0078-subsets]]'
---

## Explanations

Two approaches are preserved: one using an `unordered_set` to track available elements (`erase`/`insert` per call), and a cleaner swap-based pivot method. The shift suggests the solver first reached for explicit availability tracking before recognizing that in-place swapping achieves the same effect more naturally.

### Mistake Notes
- [[representation_shift]]: first approach used set-based element removal, then switched to swap-based pivot approach

### Related Reasoning
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: shared [[representation_shift]] pattern
- [[leetcode/0017-letter-combinations-of-a-phone-number/NOTES|0017-letter-combinations-of-a-phone-number]]: shared [[representation_shift]] pattern
- [[leetcode/0019-remove-nth-node-from-end-of-list/NOTES|0019-remove-nth-node-from-end-of-list]]: shared [[representation_shift]] pattern
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: shared [[representation_shift]] pattern
- [[leetcode/0078-subsets/NOTES|0078-subsets]]: shared [[representation_shift]] pattern

### Signals
- `another way to solve this is to take a pivot for each position and try all the elements at that position`
- `see the code for better understanding`
- commented-out set-based approach with explicit `erase`/`insert` preserved alongside swap approach
