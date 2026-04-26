---
problem_id: '0091'
platform: 'leetcode'
title: 'Decode Ways'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0091-decode-ways'
primary_tags:
  - '[[dp]]'
subtle_tags:
  - '[[dp_translation_friction]]'
candidate_tags: []
mistakes:
  - '[[micro_hesitation]]'
related:
  - '[[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]'
  - '[[leetcode/0115-distinct-subsequences/NOTES|0115-distinct-subsequences]]'
  - '[[leetcode/1143-longest-common-subsequence/NOTES|1143-longest-common-subsequence]]'
  - '[[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]'
---

## Explanations

The solver derived the recurrence from manually expanded examples rather than recognizing the standard Fibonacci-like structure immediately. The zero-handling is implemented via a preprocessing step that groups trailing zeros with their preceding digit, which adds friction compared to the more common approach of handling zeros inline within the recurrence. The multiple worked examples suggest the zero edge cases were a source of uncertainty.

### Subtle Tags
- [[dp_translation_friction]]: the conceptual recurrence is understood but the mechanical translation between forms (`brute force -> memo -> bottom-up -> space-optimized`) causes friction or error

### Mistake Notes
- [[micro_hesitation]]: the zero-handling logic with digit grouping (while loop consuming trailing zeros) adds mechanical complexity not present in the standard recurrence

### Related Reasoning
- [[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]: both start from a simple recurrence but still lean on worked examples before the transition feels safe, a shared [[dp_translation_friction]] with [[micro_hesitation]]
- [[leetcode/0115-distinct-subsequences/NOTES|0115-distinct-subsequences]]: both appear to derive the DP from counted examples before the table mechanics feel stable, which is shared [[dp_translation_friction]] with [[micro_hesitation]]
- [[leetcode/1143-longest-common-subsequence/NOTES|1143-longest-common-subsequence]]: both spend effort certifying ordinary recurrence mechanics rather than the overall decomposition, another case of [[dp_translation_friction]] with [[micro_hesitation]]
- [[leetcode/0010-regular-expression-matching/NOTES|0010-regular-expression-matching]]: both comments are dominated by case-by-case recurrence construction, so the shared basis is [[dp_translation_friction]]

### Signals
- manual worked examples for `s = 11106`, `s = 101106`, and `s = 2226` in comments
- extensive derivation of recurrence from concrete examples
- custom digit-grouping preprocessing to handle zeros
