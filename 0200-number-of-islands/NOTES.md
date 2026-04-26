---
problem_id: '0200'
platform: 'leetcode'
title: 'Number of Islands'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0200-number-of-islands'
primary_tags:
  - '[[graph-bfs]]'
  - '[[matrix]]'
subtle_tags:
  - '[[visited_timing_sensitivity]]'
candidate_tags: []
mistakes:
  - '[[micro_hesitation]]'
related:
  - '[[leetcode/0329-longest-increasing-path-in-a-matrix/NOTES|0329-longest-increasing-path-in-a-matrix]]'
  - '[[leetcode/0787-cheapest-flights-within-k-stops/NOTES|0787-cheapest-flights-within-k-stops]]'
  - '[[leetcode/0007-reverse-integer/NOTES|0007-reverse-integer]]'
  - '[[leetcode/0048-rotate-image/NOTES|0048-rotate-image]]'
  - '[[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]'
---

## Explanations

The solver explicitly flagged the visited-timing subtlety: marking cells as visited `at enqueue` time (when pushed to queue) rather than `at dequeue` time (when popped) is critical to avoid duplicate processing. The "v v imp" emphasis suggests this was likely a bug encountered during development.

### Subtle Tags
- [[visited_timing_sensitivity]]: correctness depends on WHEN a node is marked visited (`at enqueue` vs `at dequeue`, before vs after processing) — subtle BFS/DFS bugs

### Mistake Notes
- [[micro_hesitation]]: Explicit note about when to mark visited -- `at enqueue` vs `at dequeue` -- suggests this was a source of friction

### Related Reasoning
- [[leetcode/0329-longest-increasing-path-in-a-matrix/NOTES|0329-longest-increasing-path-in-a-matrix]]: both show [[visited_timing_sensitivity]]
- [[leetcode/0787-cheapest-flights-within-k-stops/NOTES|0787-cheapest-flights-within-k-stops]]: both show [[visited_timing_sensitivity]]
- [[leetcode/0007-reverse-integer/NOTES|0007-reverse-integer]]: shared [[micro_hesitation]] pattern
- [[leetcode/0048-rotate-image/NOTES|0048-rotate-image]]: shared [[micro_hesitation]] pattern
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: shared [[micro_hesitation]] pattern

### Signals
- Comment: note `grid[newi][newj] = 0`; this step is v v imp
- Comment: `if you place it after q.pop(), then all the fronts will consider this element again and again`
