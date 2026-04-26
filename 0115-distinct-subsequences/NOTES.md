---
problem_id: '0115'
platform: 'leetcode'
title: 'Distinct Subsequences'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0115-distinct-subsequences'
primary_tags:
  - '[[dp]]'
  - '[[take-dont-take]]'
subtle_tags:
  - '[[dp_translation_friction]]'
candidate_tags: []
mistakes:
  - '[[micro_hesitation]]'
related:
  - '[[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]'
  - '[[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]'
  - '[[leetcode/1143-longest-common-subsequence/NOTES|1143-longest-common-subsequence]]'
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
---

## Explanations

The solver appears to have built this solution incrementally through all three DP stages -- brute-force backtracking, top-down memoization, and bottom-up tabulation -- keeping each version as documentation. The "forced take and don't take" comment suggests the take/skip recurrence needed explicit reasoning about why both branches must always be explored.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error

### Mistake Notes
- [[micro_hesitation]]: All three forms preserved (brute force, memo, bottom-up) suggests the translation path was deliberate and possibly required working through each stage

### Related Reasoning
- [[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]: both show [[dp_translation_friction]] with shared [[micro_hesitation]]
- [[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]: both show [[dp_translation_friction]] with shared [[micro_hesitation]]
- [[leetcode/1143-longest-common-subsequence/NOTES|1143-longest-common-subsequence]]: both show [[dp_translation_friction]] with shared [[micro_hesitation]]
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: both show [[dp_translation_friction]]
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[dp_translation_friction]]

### Signals
- Three commented-out solution stages: `backtracking O(2^m)`, `backtracking + memoization, top-down dp`, and active `bottom-up dp, O(m * n)`
- Comment: `forced take and don't take as we need to try forward as well`
