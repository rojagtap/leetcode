---
problem_id: '1143'
platform: 'leetcode'
title: 'Longest Common Subsequence'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '1143-longest-common-subsequence'
primary_tags:
  - '[[dp]]'
subtle_tags:
  - '[[dp_translation_friction]]'
candidate_tags: []
mistakes:
  - '[[micro_hesitation]]'
related:
  - '[[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]'
  - '[[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]'
  - '[[leetcode/0115-distinct-subsequences/NOTES|0115-distinct-subsequences]]'
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
---

## Explanations

The solver appears to have implemented both top-down and bottom-up forms, keeping the top-down version commented out. The explicit commentary about recursion directions ("going either `i + 1` or `j + 1` or both") suggests the dp_translation_friction of converting the recurrence into iteration was a deliberate exercise rather than trivial.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error

### Mistake Notes
- [[micro_hesitation]]: kept both top-down and bottom-up implementations, suggesting the memo-to-tabulation translation was practiced explicitly

### Related Reasoning
- [[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]: both show [[dp_translation_friction]] with shared [[micro_hesitation]]
- [[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]: both show [[dp_translation_friction]] with shared [[micro_hesitation]]
- [[leetcode/0115-distinct-subsequences/NOTES|0115-distinct-subsequences]]: both show [[dp_translation_friction]] with shared [[micro_hesitation]]
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: both show [[dp_translation_friction]]
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[dp_translation_friction]]

### Signals
- commented-out top-down memoization solution preserved alongside active bottom-up solution
- comment 'for top-down it is simple recursion with memoization' followed by 'bottom up is fairly simple as well' suggests the solver walked through the translation deliberately
- comment `notice that for every recursion we are going either i + 1 or j + 1 or both` articulates the index-direction insight needed for bottom-up
