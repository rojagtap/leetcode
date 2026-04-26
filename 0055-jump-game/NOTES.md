---
problem_id: '0055'
platform: 'leetcode'
title: 'Jump Game'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0055-jump-game'
primary_tags:
  - '[[greedy]]'
  - '[[dp]]'
subtle_tags:
  - '[[counterexample_disproof_pivot]]'
  - '[[greedy_skip_justification]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
  - '[[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]'
  - '[[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]'
  - '[[leetcode/0337-house-robber-iii/NOTES|0337-house-robber-iii]]'
  - '[[leetcode/0746-min-cost-climbing-stairs/NOTES|0746-min-cost-climbing-stairs]]'
---

## Explanations

The solver explicitly constructed two counterexamples to disprove simpler approaches before converging on the backward goal-shifting greedy. The comment "if max jump can go > goal, then some jump < max can reach goal" captures the greedy skip justification -- once position i can reach the current goal, all positions to the right of i that could also reach the goal are irrelevant. The progression from bruteforce memoization to greedy suggests the proof that greedy works required deliberate reasoning.

### Subtle Tags
- [[counterexample_disproof_pivot]]: solver proposes an approach, then constructs or recalls a specific counter-example to disprove it, using the failure to pivot to the correct approach
- [[greedy_skip_justification]]: proving that when a running condition fails at position `i`, all positions `j < i` can be skipped rather than retried incrementally

### Mistake Notes
- [[wrong_path]]: considered and disproved two simpler heuristics (check for 0, check reachability before 0) using specific counterexamples before arriving at the goal-shifting greedy

### Related Reasoning
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: both show [[counterexample_disproof_pivot]] and [[greedy_skip_justification]] with shared [[wrong_path]]
- [[leetcode/0031-next-permutation/NOTES|0031-next-permutation]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0152-maximum-product-subarray/NOTES|0152-maximum-product-subarray]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0337-house-robber-iii/NOTES|0337-house-robber-iii]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]
- [[leetcode/0746-min-cost-climbing-stairs/NOTES|0746-min-cost-climbing-stairs]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]]

### Signals
- why can't we directly check for `0` in `nums` and return false if found? this test case: `[2, 0, 0]`
- why can't we check all values from `0` to `n` such that before arriving at a `0`, `i + nums[i]` should reach `n`? this test case: `[3, 0, 0, 1, 4]`
- if `max jump > goal`, then some smaller jump can still reach `goal`
- commented-out bruteforce DFS+memoization approach preserved
