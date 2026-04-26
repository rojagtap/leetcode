---
problem_id: '3914'
platform: 'leetcode'
title: 'Minimum Operations to Make Array Non Decreasing'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '3914-minimum-operations-to-make-array-non-decreasing'
primary_tags:
  - '[[greedy]]'
subtle_tags: []
candidate_tags:
  - '[[suffix_add_collapses_to_adjacent_diffs]]: when an allowed operation adds a uniform `+x` to a contiguous suffix (or any range whose left edge is the current dip), it preserves all relative differences strictly to the right of that edge, so non-adjacent comparisons can be skipped and only `max(0, nums[i-1] - nums[i])` per index needs to be paid'
mistakes:
  - '[[wrong_path]]'
  - '[[stayed_local]]'
related:
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
---

## Explanations

The contest solve walked a long way: monotonic stack of left-greater indices, a parallel `add[]` accumulator for cumulative `+x` applied to each position, and per-index diff arithmetic against `nums[leftbig[i]] + add[leftbig[i]]`. The post-mortem comment is the actual learning: because every operation is a uniform add to a suffix starting at or before the current dip, the relative gap between any two positions on the right of that boundary is preserved. So the only place a deficit can be observed is at an adjacent pair `(i-1, i)` -- if `nums[i-1] > nums[i]`, the cost is exactly `nums[i-1] - nums[i]`, regardless of any further dips ahead. Future-self trap: the worked example `[..., 10, 8, 9, ...]` is the one that proves left-greater is the wrong frame -- when we bump `8`, `9` rises with it, so the left-greater of `9` (which is `10`, not `8`) is irrelevant. Looking for left-greater feels right because the constraint mentions "non-decreasing", but the operation's translation invariance is what the structure actually depends on.

### Mistake Notes
- [[wrong_path]]: full monotonic-stack-with-cumulative-add solution kept commented at the bottom of the file -- accurate but a strict superset of what the operation requires
- [[stayed_local]]: the simplification only appears once you reason about the operation globally (suffix-add preserves rightward relative diffs); during the contest the solver reached for the local "find the left greater element" tool instead

### Related Reasoning
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: same arc -- a full prefix/suffix-max bookkeeping approach is later collapsed to a two-pointer scan once an algebraic argument shows the "true" opposite-side max is irrelevant when the binding constraint is local; the proof obligation is the structural twin of "diffs are relative" here
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: shared [[wrong_path]] -- a heavier representation (reverse BFS / monotonic stack) was carried to completion before the solver realized a directional / invariance argument made the lighter sweep correct

### Signals
- block comment opens with `looking at the problem during the contest, i figured that we need to go from left to right and whenever there is a dip, we need to fix it irrespective of what's ahead`
- block comment continues `now later, looking at the solutions, i realize that while my solution is accurate, the entire monotonic stack and left greater idea is redundant`
- block comment names the disproving cases: `nums = [..., 10, 9, 8, ...]` (bumping `9` also bumps `8`) and `nums = [..., 10, 8, 9, ...]` (bumping `8`, `9` is already covered)
- final active solution is one loop: `x += max(0, nums[i - 1] - nums[i])`
- the entire monotonic-stack version is preserved as a commented-out class at the bottom of the source
