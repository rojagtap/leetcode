---
problem_id: '3915'
platform: 'leetcode'
title: 'Maximum Sum of Alternating Subsequence With Distance at Least K'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '3915-maximum-sum-of-alternating-subsequence-with-distance-at-least-k'
primary_tags:
  - '[[dp]]'
  - '[[take-dont-take]]'
  - '[[segment-tree]]'
subtle_tags:
  - '[[dp_translation_friction]]'
candidate_tags:
  - '[[reverse_iteration_collapses_next_greater]]: when sweeping right-to-left and only inserting future-DP results into a value-indexed structure, querying the half-line `(nums[i], MAX]` (or `[1, nums[i])`) is equivalent to querying the strictly-next-greater (or smaller) seen-so-far value -- no ordered set is needed, point-update + range-max suffices'
mistakes:
  - '[[representation_shift]]'
  - '[[proof_gap]]'
related:
  - '[[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]'
  - '[[leetcode/0300-longest-increasing-subsequence/NOTES|0300-longest-increasing-subsequence]]'
  - '[[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]'
  - '[[leetcode/0494-target-sum/NOTES|0494-target-sum]]'
---

## Explanations

The note that matters is the value-axis collapse. The brute-force is the standard alternating take-or-skip DP with two states (`up`, `down`) and a `prev` value, both a forward jump of `k` (take) and `+1` (skip). At `n = 10^5` the `(i, prev)` cartesian product is O(n^2) memo, so `prev` cannot stay in the state. The fix is to flip the perspective: index the DP by the value picked at position `i`, and keep two value-indexed structures `up[v]` and `down[v]` storing the best score achievable when the next pick (k away) must respond to a chosen value `v`. Because the sweep runs right-to-left, only positions `>= i + k` have been inserted by the time we evaluate position `i`, so `down.query(nums[left] + 1, MAX)` returns the best `down`-state score among future positions whose chosen value strictly beats `nums[left]` -- which is exactly the "next-greater future value" the solver originally thought required a sorted set with a successor query. The `+1` half-line over a static value domain is equivalent to a successor query precisely because the structure only contains the future. This is the trick. It is easy to miss because in forward sweeps the same query would not be equivalent.

Future-self trap: the second take-or-skip formulation (`max(if (cond) dfs(i + k, nums[i], down), dfs(i + 1, prev, up))`) is the textbook one and the solver only "just realized" it after writing the inner-loop variant. When the recurrence "feels nested" it usually means the skip choice is being expressed as an inner loop instead of an explicit `dfs(i + 1, ...)` branch -- collapse it to two recursive arms before reasoning about complexity.

Note on the segment tree: the value domain is `[1, 10^5]` per the constraints, so the trees are sized to `1e5` directly with no coordinate compression. `NEG = LLONG_MIN / 4` is the empty sentinel chosen so additions cannot overflow. Both `up` and `down` are point-update / range-max only.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error -- here the friction shows up at the memo step, where `prev` is in the state space until the value-indexed reformulation removes it

### Mistake Notes
- [[representation_shift]]: the data structure proposed first was a sorted set with a `next greater than nums[i]` lookup; the solver then realized that under reverse iteration the same answer falls out of `range_max(nums[i] + 1, MAX)` on a value-indexed segment tree, so the abstraction switched mid-design from ordered set + successor query to value-indexed range tree
- [[proof_gap]]: two in-the-moment realizations -- `i just realized this one now` next to the second take-or-skip formulation, and the explicit walk-through of why `nums[i] + 1` is sound under reverse iteration -- both are correctness arguments the solver had to construct after the fact

### Related Reasoning
- [[leetcode/0309-best-time-to-buy-and-sell-stock-with-cooldown/NOTES|0309-best-time-to-buy-and-sell-stock-with-cooldown]]: both show [[dp_translation_friction]] on a two-state alternation (`up/down` here, `hold/sell` there) where the second state variable looks like it must live in the recurrence but turns out to be removable
- [[leetcode/0300-longest-increasing-subsequence/NOTES|0300-longest-increasing-subsequence]]: structural cousin -- a per-position subsequence DP whose naive form is O(n^2) and whose canonical speedup also indexes a tree by value; reading the segment-tree refactor here is a way to revisit LIS with the same lens
- [[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]: both show [[dp_translation_friction]] -- the recurrence is understood early but the mechanical translation pipeline (brute force, memo, indexed-DP) is where the work actually happens
- [[leetcode/0494-target-sum/NOTES|0494-target-sum]]: both share `[[take-dont-take]]` framing where the brute-force is two recursive arms before any indexing trick is applied

### Signals
- block comment names the two recurrence forms explicitly: the inner-loop variant `dfs(i, prev, up) -> max(for (j : i ... n) if (nums[j] > nums[prev]) dfs(j + k, nums[j], down))` and the textbook form `dfs(i, prev, up) -> max(if (nums[i] > prev) dfs(i + k, nums[i], down), dfs(i + 1, prev, up))` with a parenthetical `(i just realized this one now)`
- block comment lays out the `O(n^2)` ceiling and rules out greedy on both axes (`if you always pick i + k... if you always pick the max value...`)
- block comment records the failed sorted-set frame: `note that initially, i thought we have to keep all the values seen so far from j = i + k to n in a sorted set so we can query the next greater value or the next smaller value than nums[i]. but i was wrong`
- block comment justifies the value-indexed query under reverse iteration: `since we are going in reverse (like in any dp) i.e. we are iterating n ... j, we can simply try for nums[i] + 1 and - 1, because we only have results up till j. so it doesn't matter if you query the next greater number or just nums[i] + 1`
- final solution: two value-indexed segment trees `up` and `down`, point-updates at `nums[right]`, range-max queries `down.query(nums[left] + 1, 1e5)` and `up.query(1, nums[left] - 1)`
