---
problem_id: '0057'
platform: 'leetcode'
title: 'Insert Interval'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0057-insert-interval'
primary_tags:
  - '[[interval-merge]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The comment labels two different cases as "case 2", which appears to be a minor documentation slip rather than a logic error. The three-phase approach (copy before, merge overlapping, copy after) is clean and shows no significant friction.

### Signals
- `case 2: lies between starti and endi so no changes required`
- `case 2: need to merge the next intervals`
