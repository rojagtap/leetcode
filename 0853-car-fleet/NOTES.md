---
problem_id: '0853'
platform: 'leetcode'
title: 'Car Fleet'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0853-car-fleet'
primary_tags:
  - '[[sorting]]'
  - '[[stack]]'
subtle_tags:
  - '[[greedy_skip_justification]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0011-container-with-most-water/NOTES|0011-container-with-most-water]]'
  - '[[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]'
  - '[[leetcode/0055-jump-game/NOTES|0055-jump-game]]'
  - '[[leetcode/0134-gas-station/NOTES|0134-gas-station]]'
  - '[[leetcode/0435-non-overlapping-intervals/NOTES|0435-non-overlapping-intervals]]'
---

## Explanations

The solver explicitly reasons about why intermediate merges (B meeting C before A) do not affect the final fleet count -- only the front car's arrival time matters. The observation that the stack reduces to tracking only the current fleet front suggests the solver initially thought a full stack was needed, then realized the greedy invariant means only the top is ever consulted.

### Subtle Tags
- [[greedy_skip_justification]]: proving that when a running condition fails at position `i`, all positions `j < i` can be skipped rather than retried incrementally

### Related Reasoning
- [[leetcode/0011-container-with-most-water/NOTES|0011-container-with-most-water]]: both show [[greedy_skip_justification]]
- [[leetcode/0045-jump-game-ii/NOTES|0045-jump-game-ii]]: both show [[greedy_skip_justification]]
- [[leetcode/0055-jump-game/NOTES|0055-jump-game]]: both show [[greedy_skip_justification]]
- [[leetcode/0134-gas-station/NOTES|0134-gas-station]]: both show [[greedy_skip_justification]]
- [[leetcode/0435-non-overlapping-intervals/NOTES|0435-non-overlapping-intervals]]: both show [[greedy_skip_justification]]

### Signals
- 'if two cars are in a fleet, they will both go in the same slower speed of both i.e, the front car'
- 'Note that even if B and C meet before meeting A, it doesn't matter as all three are eventually going to go with A's speed'
- 'although we are using a stack, we only need the top always' -- reasons that constant space suffices
