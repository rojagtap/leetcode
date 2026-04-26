---
problem_id: '0078'
platform: 'leetcode'
title: 'Subsets'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0078-subsets'
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
  - '[[leetcode/0046-permutations/NOTES|0046-permutations]]'
---

## Explanations

Both iterative power-set construction and recursive backtracking are preserved. The comment "another way" suggests the solver explored both representations, likely arriving at backtracking after the iterative approach. Both are clean with no strong friction.

### Mistake Notes
- [[representation_shift]]: two approaches preserved: iterative (add new number to all existing subsets) and backtracking

### Related Reasoning
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: shared [[representation_shift]] pattern
- [[leetcode/0017-letter-combinations-of-a-phone-number/NOTES|0017-letter-combinations-of-a-phone-number]]: shared [[representation_shift]] pattern
- [[leetcode/0019-remove-nth-node-from-end-of-list/NOTES|0019-remove-nth-node-from-end-of-list]]: shared [[representation_shift]] pattern
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: shared [[representation_shift]] pattern
- [[leetcode/0046-permutations/NOTES|0046-permutations]]: shared [[representation_shift]] pattern

### Signals
- `another way of solving this problem is classic backtracking`
- iterative approach: start with an empty vector and add new numbers to all current subsets
