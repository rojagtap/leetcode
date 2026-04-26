---
problem_id: '0560'
platform: 'leetcode'
title: 'Subarray Sum Equals K'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0560-subarray-sum-equals-k'
primary_tags:
  - '[[hashmap]]'
  - '[[prefix-sum]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The solver notes that negative values break the sliding window approach, forcing the pivot to prefix-sum hashing. The inline screenshot and external reference below were kept from the original NOTES.md — their presence suggests the prefix-sum correctness argument was non-trivial enough to warrant external documentation rather than a terse inline comment.

### Why prefix sum works

<img width="760" alt="Screenshot 2023-11-15 at 11 24 41 PM" src="https://github.com/rojagtap/leetcode/assets/42299342/e0416515-dfb5-45ef-a624-64ec743feb71">

### References

- https://takeuforward.org/arrays/count-subarray-sum-equals-k/

### Signals
- `just like every subarray sum/product problem, we can do this very easily using sliding window/prefixsum but the problem comes when there are -ve values`
- `this is very similar to two-sum but here instead of individual numbers, we have to hash prefixsum`
- Preserved external screenshot + takeuforward reference from the original user-authored NOTES.md, suggesting the prefix-sum proof needed visual/external justification
