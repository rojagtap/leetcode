---
problem_id: '0435'
platform: 'leetcode'
title: 'Non-overlapping Intervals'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0435-non-overlapping-intervals'
primary_tags:
  - '[[greedy]]'
  - '[[interval-merge]]'
  - '[[sorting]]'
subtle_tags:
  - '[[greedy_skip_justification]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0011-container-with-most-water/NOTES|0011-container-with-most-water]]'
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
  - '[[leetcode/0055-jump-game/NOTES|0055-jump-game]]'
  - '[[leetcode/0134-gas-station/NOTES|0134-gas-station]]'
  - '[[leetcode/0853-car-fleet/NOTES|0853-car-fleet]]'
---

## Explanations

The greedy choice -- when two intervals overlap, discard the one with the larger end -- is justified by the comment's reasoning that keeping the shorter-ending interval maximizes room for subsequent non-overlapping intervals. The phrasing "only if it is not at all possible to keep it" suggests the solver needed to convince themselves that this local choice is globally optimal.

### Subtle Tags
- [[greedy_skip_justification]]: proving that when a running condition fails at position `i`, all positions `j < i` can be skipped rather than retried incrementally

### Related Reasoning
- [[leetcode/0011-container-with-most-water/NOTES|0011-container-with-most-water]]: both show [[greedy_skip_justification]]
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: both show [[greedy_skip_justification]]
- [[leetcode/0055-jump-game/NOTES|0055-jump-game]]: both show [[greedy_skip_justification]]
- [[leetcode/0134-gas-station/NOTES|0134-gas-station]]: both show [[greedy_skip_justification]]
- [[leetcode/0853-car-fleet/NOTES|0853-car-fleet]]: both show [[greedy_skip_justification]]

### Signals
- 'delete the one whose end is greater, this ensures that we delete the next one after this only if it is not at all possible to keep it'
