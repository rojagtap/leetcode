---
problem_id: '0017'
platform: 'leetcode'
title: 'Letter Combinations of a Phone Number'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0017-letter-combinations-of-a-phone-number'
primary_tags:
  - '[[backtracking]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[representation_shift]]'
related:
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
  - '[[leetcode/0019-remove-nth-node-from-end-of-list/NOTES|0019-remove-nth-node-from-end-of-list]]'
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
  - '[[leetcode/0046-permutations/NOTES|0046-permutations]]'
  - '[[leetcode/0078-subsets/NOTES|0078-subsets]]'
---

## Explanations

Two distinct implementations are present -- recursive backtracking and iterative subset expansion. The comment explicitly names both strategies, suggesting the solver tried or considered the iterative approach before settling on backtracking. The iterative version's post-hoc filtering step (`checking subset.size() == digits.size()`) appears slightly wasteful, which may have motivated the switch.

### Mistake Notes
- [[representation_shift]]: iterative subset-building approach commented out in favor of recursive backtracking

### Related Reasoning
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: shared [[representation_shift]] pattern
- [[leetcode/0019-remove-nth-node-from-end-of-list/NOTES|0019-remove-nth-node-from-end-of-list]]: shared [[representation_shift]] pattern
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: shared [[representation_shift]] pattern
- [[leetcode/0046-permutations/NOTES|0046-permutations]]: shared [[representation_shift]] pattern
- [[leetcode/0078-subsets/NOTES|0078-subsets]]: shared [[representation_shift]] pattern

### Signals
- comment: `can be solved using classic backtracking as well as appending new character to existing subset`
- second approach (iterative subset expansion) preserved as commented-out code
