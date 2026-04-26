---
problem_id: '0070'
platform: 'leetcode'
title: 'Climbing Stairs'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '0070-climbing-stairs'
primary_tags:
  - '[[dp]]'
subtle_tags:
  - '[[dp_translation_friction]]'
candidate_tags: []
mistakes:
  - '[[micro_hesitation]]'
related:
  - '[[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]'
  - '[[leetcode/0115-distinct-subsequences/NOTES|0115-distinct-subsequences]]'
  - '[[leetcode/1143-longest-common-subsequence/NOTES|1143-longest-common-subsequence]]'
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
---

## Explanations

The manual enumeration of all 8 paths for `n = 5` suggests the recurrence relation was derived empirically rather than recognized as Fibonacci immediately. The progression from recursive memoization to iterative with a DP array to two-variable rolling shows the standard DP translation pipeline, with the intermediate DP-array approach commented out mid-implementation.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error

### Mistake Notes
- [[micro_hesitation]]: commented-out `vector<int> dp(n + 1)` allocation replaced by `iminus1`/`iminus2` rolling variables; also enumerated all paths for `n = 5` manually in comments

### Related Reasoning
- [[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]: both show [[dp_translation_friction]] with shared [[micro_hesitation]]
- [[leetcode/0115-distinct-subsequences/NOTES|0115-distinct-subsequences]]: both show [[dp_translation_friction]] with shared [[micro_hesitation]]
- [[leetcode/1143-longest-common-subsequence/NOTES|1143-longest-common-subsequence]]: both show [[dp_translation_friction]] with shared [[micro_hesitation]]
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: both show [[dp_translation_friction]]
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[dp_translation_friction]]

### Signals
- extensive manual enumeration of all paths for `n = 5` in comments
- commented-out `vector<int> dp(n + 1)` replaced by `iminus1`/`iminus2` variables
- recursive memoized approach also preserved
