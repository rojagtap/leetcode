---
problem_id: '1448'
platform: 'leetcode'
title: 'Count Good Nodes in Binary Tree'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '1448-count-good-nodes-in-binary-tree'
primary_tags:
  - '[[binary-tree]]'
  - '[[graph-bfs]]'
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

The solver likely explored both BFS and DFS representations. Both are correct; the commented-out recursive DFS suggests it was written first or as an alternative, then the solver switched to iterative BFS. The representation_shift appears deliberate rather than caused by a bug.

### Mistake Notes
- [[representation_shift]]: implemented both BFS (iterative) and DFS (recursive) approaches, keeping the recursive version commented out

### Related Reasoning
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: shared [[representation_shift]] pattern
- [[leetcode/0017-letter-combinations-of-a-phone-number/NOTES|0017-letter-combinations-of-a-phone-number]]: shared [[representation_shift]] pattern
- [[leetcode/0019-remove-nth-node-from-end-of-list/NOTES|0019-remove-nth-node-from-end-of-list]]: shared [[representation_shift]] pattern
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: shared [[representation_shift]] pattern
- [[leetcode/0046-permutations/NOTES|0046-permutations]]: shared [[representation_shift]] pattern

### Signals
- commented-out recursive DFS solution alongside active iterative BFS solution
- comment 'level order traversal with passing max of prev' for BFS vs 'recursively pass the current max' for DFS
