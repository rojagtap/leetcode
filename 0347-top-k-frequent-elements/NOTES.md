---
problem_id: '0347'
platform: 'leetcode'
title: 'Top K Frequent Elements'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0347-top-k-frequent-elements'
primary_tags:
  - '[[hashmap]]'
  - '[[sorting]]'
  - '[[bucket-sort]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The solver implemented both the heap-based and bucket-sort approaches. That is useful topic information, but `bucket-sort` is a standard primary tag rather than a solver-friction concept, so it belongs in the topic layer instead of the candidate ontology.

### Signals
- Both bucket-sort `O(n)` and heap `O(k log n)` solutions are retained
- Comment for the bucket approach: `reverse the count table by creating a vector<vector<int>> of size equal to nums.size()`
