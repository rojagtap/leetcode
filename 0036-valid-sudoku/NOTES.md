---
problem_id: '0036'
platform: 'leetcode'
title: 'Valid Sudoku'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0036-valid-sudoku'
primary_tags:
  - '[[hashmap]]'
  - '[[matrix]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The comment describes both a set-based and a boolean-grid-based approach for tracking seen values, suggesting the solver considered the representation tradeoff. The implementation uses sets, and the boolean-grid alternative is noted but not pursued.

### Signals
- comment describes two alternative data structures: sets vs `9x9` boolean grids
- comment: `all this can also be achieved by having a 9x9 boolean grid for row, column, box`
