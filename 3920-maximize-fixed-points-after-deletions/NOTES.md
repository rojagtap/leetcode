---
problem_id: '3920'
platform: 'leetcode'
title: 'Maximize Fixed Points After Deletions'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '3920-maximize-fixed-points-after-deletions'
primary_tags:
  - '[[dp]]'
  - '[[binary-search]]'
  - '[[sorting]]'
subtle_tags:
  - '[[retain_vs_remove_reframing]]'
candidate_tags:
  - '[[two_axis_lis_reduction]]'
mistakes:
  - '[[wrong_path]]'
  - '[[spiral]]'
  - '[[knowledge_gap]]'
related:
  - '[[leetcode/0312-burst-balloons/NOTES|0312-burst-balloons]]'
  - '[[cf/sorting/cf-863-b-kayaking/NOTES|cf-863-b-kayaking]]'
---

## Explanations

The friction here is reframing. The contest was spent searching the *deletion* space: a `dfs(i, carry)` with `carry` = number deleted so far, then a `visited[]` to deduplicate values. The state explodes because `visited[]` has to live alongside `(i, carry)` in the cache key, so the DP cannot be memoized at `n = 10^5`. The fix is not to fix the DP -- it is to stop searching deletions and describe the *kept* set instead. Each retained index `i` with value `nums[i]` becomes a fixed point iff after `del` deletions to its left we have `i - del == nums[i]`, i.e. `del = i - nums[i]`. So eligible elements are exactly those with `i - nums[i] >= 0`, parametrized by their `diff = i - nums[i]`. For two retained eligibles `(i_1, x_1)` and `(i_2, x_2)` with `i_1 < i_2`: `x_2` shifts left once because `x_1` is kept (one fewer deletion in front of it), so `del_2 >= del_1 + 0` -- but the simple algebra is cleaner: both must remain fixed points after the same global set of deletions, and any deletion before `i_1` shifts both equally, so the relative requirement is `diff_1 <= diff_2` *and* `x_1 < x_2` (strict, because positions cannot collide). That is two-axis LIS: sort by `diff`, then run LIS on `nums`.

Future-self trap: after the contest, when staring at a working solution that "sorts by diff and runs LIS over nums", it is natural to read the sort key as a *priority* ("pick the cheapest deletions first") and start reasoning about the order in which deletions are committed. The block comment shows this rabbit-hole: partial-overlap intervals, "what if a deletion could have placed a fixed point itself", "what if the shortest diff overlaps with two longer ones". None of that matters. LIS over `(diff, nums)` does not pick an order; it picks a *subset* whose pairwise structure already implies a feasible deletion plan exists. The right shape to verbalize is: `subset of items, all pairwise compatible -> existence of a deletion plan is automatic`. Any time the explanation drifts toward "which deletion goes first", the frame has slipped back to deletion-search.

The second trap is the eligibility filter `i - nums[i] >= 0`. Items with negative diff cannot be made fixed (they would need to shift right, which deletions never do) and must be excluded *before* sorting; otherwise their `diff < 0` sneaks into the sort and pollutes the LIS. The active solution gates this with `if (i - nums[i] >= 0)` at push time, which is easy to drop on a rewrite.

### Subtle Tags
- [[retain_vs_remove_reframing]]: switching between "process and remove" to "retain until last" changes subproblem structure from dependent to independent -- here the DP over deletions is replaced by a structural condition on the kept subset, which removes the `visited[]` dimension and the `carry` dimension simultaneously

### Candidate Tags
- [[two_axis_lis_reduction]]: when the goal is "select max subset such that any two chosen items satisfy a 2-criterion order" (here `i_1 < i_2 \Rightarrow diff_1 \le diff_2 \wedge x_1 < x_2`), sort by one criterion (with appropriate tiebreak to forbid equal stacks) and run LIS over the other; eligibility (`diff >= 0`) is filtered before sorting

### Mistake Notes
- [[wrong_path]]: contest brute force was `dfs(i, carry)` with a separate `visited[]` for value-uniqueness; the bottom-of-file commented class shows the dead end -- `cache[i][carry]` is correct but `visited[]` cannot be folded into the key at `n = 10^5`, so memoization is impossible
- [[spiral]]: post-contest, after the LIS algorithm was visible, the solver kept generating "what if intervals overlap, what if shortest diff is preferred, what if a deletion could itself become a fixed point" without disproving any of them -- the loop ended only when the pairwise `(diff, value)` condition was written down
- [[knowledge_gap]]: `missing the fundamental LIS concept` is the solver's own diagnosis -- the standard pattern of "select max subset under a 2-criterion pairwise order = sort-then-LIS" was not in the toolbox

### Related Reasoning
- [[leetcode/0312-burst-balloons/NOTES|0312-burst-balloons]]: same reframing arc -- both abandon a DP that searches the *deletion / burst order* space and pivot to a structural description of what is kept; the shared signal is [[retain_vs_remove_reframing]] removing a state dimension that looked load-bearing
- [[cf/sorting/cf-863-b-kayaking/NOTES|cf-863-b-kayaking]]: shared [[spiral]] -- there a single unfalsified doubt about a greedy was formed and dropped, here a stream of unfalsified what-ifs about interval overlap; both loops ended only when one concrete structural statement (a counterexample, a pairwise condition) got written down

### Signals
- block comment narrates the contest brute force: `i first thought about bruteforce where you try all possible combinations of shifting numbers... we can take carry and i and either move the ith element to i - carry - nums[i] or skip`
- block comment records the failed memo: `the problem here is taking an entire visited state for 1e5 elements is not possible alongside carry and i`
- block comment names the post-contest spiral: `i first thought it works because we always pick the smallest diff first since it has the least number of deletions. and from here, i spiraled`, then enumerates `partial overlaps`, `which one goes first`, and `what if the shortest diff interval overlaps with two such intervals`
- block comment records the structural pivot: `for any two numbers x (at i) and y (at j) where x < y, to be able to pick both, if i < j: then diffx <= diffy because y shifts more (once for x and then for itself)`, with conclusion `that's LIS with one value sorted and other LIS`
- final solution: build `tuples` of `(i - nums[i], nums[i])` filtered by `i - nums[i] >= 0`, `sort`, then `lower_bound` LIS; commented-out class at the bottom preserves the dead-end memo with separate `visited[]` and `cache[i][carry]`
