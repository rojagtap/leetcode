---
problem_id: '0075'
platform: 'leetcode'
title: 'Sort Colors'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0075-sort-colors'
primary_tags:
  - '[[two-pointer]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The extensive manual trace in comments suggests the Dutch National Flag invariant (everything before left is 0, everything after right is 2) was verified by simulation rather than held confidently. The implementation itself is clean with no wrong paths.

### Signals
- detailed step-by-step trace of the algorithm on `[0,0,1,2,0,1,2]` in comments
