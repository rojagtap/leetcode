---
problem_id: '0076'
platform: 'leetcode'
title: 'Minimum Window Substring'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0076-minimum-window-substring'
primary_tags:
  - '[[sliding-window]]'
  - '[[hashmap]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

Clean sliding window implementation with frequency counting and a matches counter. The approach comment describes the expand-then-shrink pattern concisely. No significant friction signals.

### Signals
- first go in increasing sequence until all characters of `t` are present
- then trim the sequence from the left until all characters are present and update `minlength` with each trim
