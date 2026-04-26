---
problem_id: '0763'
platform: 'leetcode'
title: 'Partition Labels'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0763-partition-labels'
primary_tags:
  - '[[greedy]]'
subtle_tags:
  - '[[local_constraint_global_implication]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/1899-merge-triplets-to-form-target-triplet/NOTES|1899-merge-triplets-to-form-target-triplet]]'
---

## Explanations

No stronger latent-friction inference is supported beyond the current comments and prior notes.

### Subtle Tags
- [[local_constraint_global_implication]]: a local constraint (e.g., "no element exceeds `target[j]`") has a global filtering effect that eliminates entire candidates

### Related Reasoning
- [[leetcode/1899-merge-triplets-to-form-target-triplet/NOTES|1899-merge-triplets-to-form-target-triplet]]: both show [[local_constraint_global_implication]]
