---
problem_id: '0003'
platform: 'leetcode'
title: 'Longest Substring Without Repeating Characters'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0003-longest-substring-without-repeating-characters'
primary_tags:
  - '[[sliding-window]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The comment spells out the left-pointer contraction logic in detail, which suggests the shrink-on-duplicate step was not yet automatic. No wrong path is evident -- the approach is correct from the start.

### Signals
- comment walks through the window shrink step: `remove all characters from left to indexof(seen character) from the set`
