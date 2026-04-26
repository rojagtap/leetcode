---
problem_id: '0787'
platform: 'leetcode'
title: 'Cheapest Flights Within K Stops'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0787-cheapest-flights-within-k-stops'
primary_tags:
  - '[[dijkstra]]'
  - '[[graph-bfs]]'
subtle_tags:
  - '[[visited_timing_sensitivity]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0200-number-of-islands/NOTES|0200-number-of-islands]]'
  - '[[leetcode/0329-longest-increasing-path-in-a-matrix/NOTES|0329-longest-increasing-path-in-a-matrix]]'
---

## Explanations

The solver notes that standard Dijkstra visited-node pruning does not apply here because a longer (more expensive) path with fewer stops may lead to a cheaper overall result than a shorter path that exhausts the stop budget. The switch from `priority_queue` to a plain queue suggests the solver realized the stop count `k` acts like BFS levels, making a min-heap unnecessary for the `k` dimension.

### Subtle Tags
- [[visited_timing_sensitivity]]: correctness depends on WHEN a node is marked visited (`at enqueue` vs `at dequeue`, before vs after processing) — subtle BFS/DFS bugs

### Related Reasoning
- [[leetcode/0200-number-of-islands/NOTES|0200-number-of-islands]]: both show [[visited_timing_sensitivity]]
- [[leetcode/0329-longest-increasing-path-in-a-matrix/NOTES|0329-longest-increasing-path-in-a-matrix]]: both show [[visited_timing_sensitivity]]

### Signals
- `the only terminating condition here is for a given path kpath > k no other special condition for cycles or visited nodes`
- Commented-out `priority_queue` replaced with a plain queue: `this is similar to level-order traversal so front will always be the smallest k`
