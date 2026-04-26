---
problem_id: '0005'
platform: 'leetcode'
title: 'Longest Palindromic Substring'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0005-longest-palindromic-substring'
primary_tags:
  - '[[two-pointer]]'
  - '[[center-expansion]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The comment manually traces substrings for a small example before describing the center-expansion approach, which suggests the solver worked through a concrete case before trusting the center-symmetry argument. That is useful evidence, but it is better captured in the explanation than elevated into its own reasoning tag.

### Signals
- comment enumerates partial palindromes for `babad` before settling on `expand-from-center`
