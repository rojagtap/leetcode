---
problem_id: '1899'
platform: 'leetcode'
title: 'Merge Triplets to Form Target Triplet'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '1899-merge-triplets-to-form-target-triplet'
primary_tags:
  - '[[greedy]]'
subtle_tags:
  - '[[local_constraint_global_implication]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0763-partition-labels/NOTES|0763-partition-labels]]'
---

## Explanations

The solver's emphasis ("AT ALL", "NEVER") and the worked counter-example suggest the local_constraint_global_implication insight -- that exceeding the target in any single position disqualifies the entire triplet -- was the crux of the problem. Once that filtering rule is clear, the rest is a straightforward check. The worked example in the comment likely served as the solver's own proof of correctness.

### Subtle Tags
- [[local_constraint_global_implication]]: a local constraint (e.g., "no element exceeds `target[j]`") has a global filtering effect that eliminates entire candidates

### Related Reasoning
- [[leetcode/0763-partition-labels/NOTES|0763-partition-labels]]: both show [[local_constraint_global_implication]]

### Signals
- comment: if any value at index `j` is greater than `target[j]`, where `j = 0, 1, 2`, then we cannot use this triplet at all -- the caps in the source note suggest this was the key insight
- comment provides a worked example: `even if we use the 2 from the first triplet... given that there is an 8 at the second position which is > 7... this can NEVER be used to combine further`
