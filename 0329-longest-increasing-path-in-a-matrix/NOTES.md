---
problem_id: '0329'
platform: 'leetcode'
title: 'Longest Increasing Path in a Matrix'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0329-longest-increasing-path-in-a-matrix'
primary_tags:
  - '[[graph-dfs]]'
  - '[[memoization]]'
  - '[[matrix]]'
subtle_tags:
  - '[[visited_timing_sensitivity]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0200-number-of-islands/NOTES|0200-number-of-islands]]'
  - '[[leetcode/0787-cheapest-flights-within-k-stops/NOTES|0787-cheapest-flights-within-k-stops]]'
---

## Explanations

The solver explicitly notes why a visited array is unnecessary -- the strictly-increasing constraint on cell values means the traversal cannot revisit. This observation is subtle because most grid DFS problems do require visited tracking, and recognizing when it is redundant (because the problem structure provides the same guarantee) is the key insight here.

### Subtle Tags
- [[visited_timing_sensitivity]]: correctness depends on WHEN a node is marked visited (`at enqueue` vs `at dequeue`, before vs after processing) — subtle BFS/DFS bugs

### Related Reasoning
- [[leetcode/0200-number-of-islands/NOTES|0200-number-of-islands]]: both show [[visited_timing_sensitivity]]
- [[leetcode/0787-cheapest-flights-within-k-stops/NOTES|0787-cheapest-flights-within-k-stops]]: both show [[visited_timing_sensitivity]]

### Signals
- 'no visited array needed because the condition to go ahead is prev cell < next cell so it is not possible to go back to a visited cell'
