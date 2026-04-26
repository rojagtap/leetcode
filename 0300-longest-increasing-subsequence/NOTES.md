---
problem_id: '0300'
platform: 'leetcode'
title: 'Longest Increasing Subsequence'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0300-longest-increasing-subsequence'
primary_tags:
  - '[[dp]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The solver appears to have built intuition by manually tracing all subsequences for a sample input before abstracting to the DP recurrence. The detailed worked example suggests the transition from enumerating subsequences to caching per-index LIS lengths required deliberate reasoning.

### Signals
- Comment traces through a full worked example enumerating all subsequences before arriving at the DP formulation
- `instead of having all the sequences, we can have a array containing the LIS until each i in nums`
