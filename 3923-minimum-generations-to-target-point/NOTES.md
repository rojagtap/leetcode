---
problem_id: '3923'
platform: 'leetcode'
title: 'Minimum Generations to Target Point'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '3923-minimum-generations-to-target-point'
primary_tags:
  - '[[graph-bfs]]'
  - '[[complete-search]]'
subtle_tags:
  - '[[counterexample_disproof_pivot]]'
candidate_tags:
  - '[[bfs_terminate_on_set_growth_stall]]'
mistakes:
  - '[[wrong_path]]'
  - '[[spiral]]'
related:
  - '[[leetcode/0055-jump-game/NOTES|0055-jump-game]]'
---

## Explanations

The right shape is BFS over the *set of reachable points*, where one "generation" is one BFS layer. The non-obvious part -- and the entire contest spiral -- is the termination condition. Naive BFS terminates when the queue empties; here the pair-midpoint operation can keep regenerating already-seen points indefinitely, so the queue never empties. The fix is to terminate when the *set stops growing*: each layer, take pairs only from the current set, accumulate the candidate midpoints into `next`, and after filtering out points already in `q`, if `next` is empty the set has hit its closure and the target is unreachable. The whole algorithm is just `while (set grows) { compute new midpoints; insert; ++k; }` with an early-out when the target is generated. With `n <= 20` initial points and coordinates in `[0, 6]^3`, the closure has at most `7^3 = 343` distinct points, which bounds the layer count to a constant.

Future-self trap: every "this looks unbounded" BFS deserves the question "what is the *set* I am closing over, and can I detect closure by lack of growth?" before a reachability filter is invented. The contest record shows the solver going the other direction: try to *predict* reachability up front via a global bbox (`tx >= min(x_i) && tx < max(x_i)` per axis), notice that floor breaks the upper bound, patch to per-pair bbox, and only then realize the set-growth termination would have made the entire reachability scaffolding unnecessary. The "this should've been my clue" comment names the missed signal exactly: once you know cycles are possible, the queue-empty termination is wrong, and the natural replacement is set-stalls termination.

The midpoint helper deserves one note: `floor((x1 + x2) / 2.0)` is only equivalent to integer division when the operands are non-negative, which holds here. If a future variant allows negative coordinates, switch to a sign-correct floor or the integer-division semantics break for odd negative sums.

### Subtle Tags
- [[counterexample_disproof_pivot]]: the global-bbox feasibility test (`tx >= min, tx < max` per axis) was disproved by recalling that the floor operation can prevent the maximum from being recovered, which forced the pivot away from front-loaded reachability filtering -- although the immediate next pivot (per-pair bbox) was also wrong, the disproof is what unstuck the global-bbox direction

### Candidate Tags
- [[bfs_terminate_on_set_growth_stall]]: when the BFS edge relation can regenerate already-seen states (so the queue never empties), terminate on "no new states added this layer" by partitioning the next-layer candidates against the visited set and checking emptiness; the closure of the set, not the queue, is the fixed point

### Mistake Notes
- [[wrong_path]]: a global-bbox reachability check and then a per-pair coverage check were both attempted before the BFS termination was fixed; the early commented-out classes (`// 6`, `// 5`, `// 4`, `// 3`) all carry one of these reachability filters and pre-commit to `-1` based on it, which is over-aggressive
- [[spiral]]: after recognizing cycles are possible (`should've been my clue`), the solver kept generating reachability sub-heuristics (axis-coverage, pair-interval coverage) instead of asking what BFS termination naturally handles cycles -- the right move was sitting one level above the heuristic search

### Related Reasoning
- [[leetcode/0055-jump-game/NOTES|0055-jump-game]]: both show [[counterexample_disproof_pivot]] with shared [[wrong_path]] -- a global feasibility shortcut is proposed (here `tx in [min, max)`, there `nums` contains a `0`), disproved by a constructed counterexample (here `floor` blocks the max, there `[2, 0, 0]` reaches anyway), and only then does the solver pivot to the right sweep

### Signals
- block comment opens with `another disasterclass` and `straight away came up with the bfs idea, but didn't/couldn't think of the edge cases`
- block comment names the missed cue verbatim: `then realized it is possible to go round and round in same points => this should've been my clue`
- block comment lists the wrong-path attempts: `i tried seeing if target x,y,z lie between min max of each, but then you might never get max value because floor`, `then came up with trying pairs of all initial points and seeing if we can get target point in between`
- block comment names the eventual pivot: `eventually realized that if the bfs can go into cycles, then we can just filter out only the new points in each cycle and based on that we can do the next.empty check`
- the failed reachability filters are preserved as the `// 6`, `// 5`, `// 4`, `// 3` commented classes at the bottom of the source -- each adds the `if (tx < minx ...) return -1;` short-circuit that the active solution removes
- final solution: `set<tuple<int, int, int>> q`, layer loop computes `next` of unseen midpoints only, terminates with `-1` when `next.empty()`
