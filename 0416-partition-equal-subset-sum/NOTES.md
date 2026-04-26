---
problem_id: '0416'
platform: 'leetcode'
title: 'Partition Equal Subset Sum'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0416-partition-equal-subset-sum'
primary_tags:
  - '[[dp]]'
  - '[[take-dont-take]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[micro_hesitation]]'
related:
  - '[[leetcode/0007-reverse-integer/NOTES|0007-reverse-integer]]'
  - '[[leetcode/0048-rotate-image/NOTES|0048-rotate-image]]'
  - '[[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]'
  - '[[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]'
  - '[[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]'
---

## Explanations

The solver hit a subtle memoization pitfall: using a boolean cache with false as the default value meant that failed subproblems were never cached and were re-explored. The fix -- switching to a tri-state int cache (-1 for unvisited, 0 for false, 1 for true) -- is a common but easy-to-forget pattern. The commented-out loop variant suggests an earlier attempt at a different recursion structure.

### Mistake Notes
- [[micro_hesitation]]: initially used boolean cache defaulting to false, causing repeated exploration of false branches; switched to int cache with -1/0/1

### Related Reasoning
- [[leetcode/0007-reverse-integer/NOTES|0007-reverse-integer]]: shared [[micro_hesitation]] pattern
- [[leetcode/0048-rotate-image/NOTES|0048-rotate-image]]: shared [[micro_hesitation]] pattern
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: shared [[micro_hesitation]] pattern
- [[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]: shared [[micro_hesitation]] pattern
- [[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]: shared [[micro_hesitation]] pattern

### Signals
- 'make sure that you also memoize false cases'
- 'if you take boolean cache and keep false as default and return only when condition is true all the false cases will be repeated'
- Commented-out loop-based alternative inside the recursion
