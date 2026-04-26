---
problem_id: '0047'
platform: 'leetcode'
title: 'Permutations II'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0047-permutations-ii'
primary_tags:
  - '[[backtracking]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

Clean extension of the permutations swap-pivot approach with a per-level visited set to skip duplicates. The comment explaining the duplicate-skip logic suggests the solver understood the invariant clearly. No strong friction signals.

### Signals
- similar to https://leetcode.com/problems/permutations/
- skip the try if the ith element is already seen at that level, this will lead to the same permutation again
