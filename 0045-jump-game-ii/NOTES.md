---
problem_id: '0045'
platform: 'leetcode'
title: 'Jump Game II'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0045-jump-game-ii'
primary_tags:
  - '[[greedy]]'
  - '[[dp]]'
subtle_tags:
  - '[[counterexample_disproof_pivot]]'
  - '[[greedy_skip_justification]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
  - '[[representation_shift]]'
related:
  - '[[leetcode/0055-jump-game/NOTES|0055-jump-game]]'
  - '[[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]'
  - '[[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]'
  - '[[leetcode/0337-house-robber-iii/NOTES|0337-house-robber-iii]]'
  - '[[leetcode/0746-min-cost-climbing-stairs/NOTES|0746-min-cost-climbing-stairs]]'
---

## Explanations

The solver likely struggled with the directionality insight: reverse BFS searches all of `[0, n)` at each step, but forward BFS exploits the fact that jumps only go forward, enabling level-by-level expansion in linear time. The presence of three preserved approaches suggests the path from `O(n^2)` reverse scan to `O(n)` forward scan was not immediate. The key invariant is that each "level" of the BFS covers a contiguous range `[l, r]`, and the next level's right boundary is the max reachable from that range.

### Subtle Tags
- [[counterexample_disproof_pivot]]: solver proposes an approach, then constructs or recalls a specific counter-example to disprove it, using the failure to pivot to the correct approach
- [[greedy_skip_justification]]: proving that when a running condition fails at position `i`, all positions `j < i` can be skipped rather than retried incrementally

### Mistake Notes
- [[wrong_path]]: started with reverse BFS (`O(n^2)`) before realizing forward direction leverages jump directionality for `O(n)`
- [[representation_shift]]: explored three distinct framings -- reverse BFS, forward BFS, and in-place DP -- before settling on forward BFS

### Related Reasoning
- [[leetcode/0055-jump-game/NOTES|0055-jump-game]]: both show [[counterexample_disproof_pivot]] and [[greedy_skip_justification]] with shared [[wrong_path]]
- [[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0337-house-robber-iii/NOTES|0337-house-robber-iii]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0746-min-cost-climbing-stairs/NOTES|0746-min-cost-climbing-stairs]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]

### Signals
- this can be `O(n^2)` as every time we search from 0 to n (for example `[1,1,1,1,1,1,1,1]`)
- if we do the same thing in forward direction, it will be `O(n)`
- we are pretty much doing the same thing in both approaches, just that since the direction of jumps is forward, we can use that to search for the next level (in bfs) in linear time
- commented-out reverse BFS and DP approaches preserved alongside active forward BFS
