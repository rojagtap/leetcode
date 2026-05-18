---
problem_id: '3931'
platform: 'leetcode'
title: 'Check Adjacent Digit Differences'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '3931-check-adjacent-digit-differences'
primary_tags:
  - '[[simulation]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

Linear pass over adjacent character pairs, subtract `'0'` to recover digit values, return `false` on the first `abs(a - b) > 2`. `n <= 100` and a fixed alphabet of digits leave no room for asymptotic friction or representation choice. `no_signal`.

### Signals
- single-loop body: `int a = s[i - 1] - '0'; int b = s[i] - '0'; if (abs(a - b) > 2) return false;`
