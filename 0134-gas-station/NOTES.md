---
problem_id: '0134'
platform: 'leetcode'
title: 'Gas Station'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0134-gas-station'
primary_tags:
  - '[[greedy]]'
subtle_tags:
  - '[[greedy_skip_justification]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0011-container-with-most-water/NOTES|0011-container-with-most-water]]'
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
  - '[[leetcode/0055-jump-game/NOTES|0055-jump-game]]'
  - '[[leetcode/0435-non-overlapping-intervals/NOTES|0435-non-overlapping-intervals]]'
  - '[[leetcode/0853-car-fleet/NOTES|0853-car-fleet]]'
---

## Explanations

The solver explicitly reasoned through the greedy skip: when the running total goes negative at position `i`, all starting positions before `i` are provably invalid, so the search jumps to `i + 1`. The uniqueness guarantee is invoked to avoid verifying the final candidate circularly.

### Subtle Tags
- [[greedy_skip_justification]]: proving that when a running condition fails at position `i`, all positions `j < i` can be skipped rather than retried incrementally

### Related Reasoning
- [[leetcode/0011-container-with-most-water/NOTES|0011-container-with-most-water]]: both show [[greedy_skip_justification]]
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: both show [[greedy_skip_justification]]
- [[leetcode/0055-jump-game/NOTES|0055-jump-game]]: both show [[greedy_skip_justification]]
- [[leetcode/0435-non-overlapping-intervals/NOTES|0435-non-overlapping-intervals]]: both show [[greedy_skip_justification]]
- [[leetcode/0853-car-fleet/NOTES|0853-car-fleet]]: both show [[greedy_skip_justification]]

### Signals
- Comment: if for some `i` the total < 0, all `j < i` don't really help, so we should move to `start = i + 1` directly
- Comment: 'if all the solutions till now didnt work, this has to' -- proof by elimination of uniqueness guarantee
