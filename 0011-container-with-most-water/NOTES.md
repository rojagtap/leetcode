---
problem_id: '0011'
platform: 'leetcode'
title: 'Container With Most Water'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0011-container-with-most-water'
primary_tags:
  - '[[two-pointer]]'
  - '[[greedy]]'
subtle_tags:
  - '[[greedy_skip_justification]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
  - '[[leetcode/0055-jump-game/NOTES|0055-jump-game]]'
  - '[[leetcode/0134-gas-station/NOTES|0134-gas-station]]'
  - '[[leetcode/0435-non-overlapping-intervals/NOTES|0435-non-overlapping-intervals]]'
  - '[[leetcode/0853-car-fleet/NOTES|0853-car-fleet]]'
---

## Explanations

The comment articulates the greedy justification: moving the shorter pointer inward is safe because all wider containers with that pointer are already dominated. The explanation suggests the solver needed to reason through why skipping those positions is correct.

### Subtle Tags
- [[greedy_skip_justification]]: proving that when a running condition fails at position `i`, all positions `j < i` can be skipped rather than retried incrementally

### Related Reasoning
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: both show [[greedy_skip_justification]]
- [[leetcode/0055-jump-game/NOTES|0055-jump-game]]: both show [[greedy_skip_justification]]
- [[leetcode/0134-gas-station/NOTES|0134-gas-station]]: both show [[greedy_skip_justification]]
- [[leetcode/0435-non-overlapping-intervals/NOTES|0435-non-overlapping-intervals]]: both show [[greedy_skip_justification]]
- [[leetcode/0853-car-fleet/NOTES|0853-car-fleet]]: both show [[greedy_skip_justification]]

### Signals
- comment: `if we wish to increase the area, we need a increase in height. So we come closer for lower heights`
