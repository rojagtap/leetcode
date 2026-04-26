---
problem_id: '0312'
platform: 'leetcode'
title: 'Burst Balloons'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0312-burst-balloons'
primary_tags:
  - '[[dp]]'
subtle_tags:
  - '[[retain_vs_remove_reframing]]'
  - '[[subproblem_independence_recognition]]'
  - '[[dp_translation_friction]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
  - '[[proof_gap]]'
related:
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
  - '[[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]'
  - '[[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]'
  - '[[leetcode/0124-binary-tree-maximum-path-sum/NOTES|0124-binary-tree-maximum-path-sum]]'
  - '[[leetcode/0198-house-robber/NOTES|0198-house-robber]]'
---

## Explanations

This is one of the most heavily annotated solutions in the set. The solver explicitly walks through why the natural burst-first decomposition creates dependent subarrays that cannot be cached, then pivots to the retain-last reframing where subproblems become independent. The bottom-up translation comment ("the translation is a bit tricky here") and the detailed explanation of why three nested loops are needed (not just two) suggest the mechanical DP translation was a separate source of friction beyond the conceptual insight.

### Subtle Tags
- [[retain_vs_remove_reframing]]: switching between "process and remove" to "retain until last" changes subproblem structure from dependent to independent
- [[subproblem_independence_recognition]]: the critical realization that decomposed subproblems share no state, enabling clean memoization — often the hardest insight in interval/partition DP
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error

### Mistake Notes
- [[wrong_path]]: initially tried take/don't take framing, then realized all balloons must be burst so it is about ordering, not selection
- [[proof_gap]]: identified that burst-first creates dependent subarrays ('left and right subarrays are dependent on each other for the right/left bounds') but needed to reason through why retain-last fixes it

### Related Reasoning
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[dp_translation_friction]] and [[subproblem_independence_recognition]] with shared [[wrong_path]]
- [[leetcode/0072-edit-distance/NOTES|0072-edit-distance]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0097-interleaving-string/NOTES|0097-interleaving-string]]: both show [[dp_translation_friction]] with shared [[wrong_path]]
- [[leetcode/0124-binary-tree-maximum-path-sum/NOTES|0124-binary-tree-maximum-path-sum]]: both show [[subproblem_independence_recognition]] with shared [[proof_gap]]
- [[leetcode/0198-house-robber/NOTES|0198-house-robber]]: both show [[dp_translation_friction]] with shared [[wrong_path]]

### Signals
- `why take/don't take doesn't work?`
- `the issue with this is if we don't burst the balloon and move ahead, it will NEVER be burst`
- `for any subarray (like [8] in the above example), we have to try every element in the other subarray as its left bound so this is not really a subproblem that we can cache`
- `instead of BURSTING each balloon iteratively...why don't we RETAIN that balloon and go left and right to obtain the optimal solution such that this balloon is burst LAST`
- `the advantage of this approach is, whatever we do in the subarrays is independent of each other`
- Long comment on bottom-up translation: `the translation is a bit tricky here` with detailed loop-order reasoning
- Three implementations retained: `backtracking -> memo -> bottom-up`
