---
problem_id: '1482'
platform: 'leetcode'
title: 'Minimum Number of Days to Make m Bouquets'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '1482-minimum-number-of-days-to-make-m-bouquets'
primary_tags:
  - '[[binary-search]]'
subtle_tags:
  - '[[binary_search_on_answer_space]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/0153-find-minimum-in-rotated-sorted-array/NOTES|0153-find-minimum-in-rotated-sorted-array]]'
  - '[[leetcode/0875-koko-eating-bananas/NOTES|0875-koko-eating-bananas]]'
  - '[[leetcode/3899-angles-of-a-triangle/NOTES|3899-angles-of-a-triangle]]'
---

## Explanations

The comment block shows the solver walking through the brute-force-to-binary-search reasoning, which is the canonical binary_search_on_answer_space insight. The inline comment justifying `left = min` suggests a brief pause to verify the search boundary, but no actual wrong path.

### Subtle Tags
- [[binary_search_on_answer_space]]: recognizing that the answer itself is monotone and searchable rather than searching the input directly

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both show [[binary_search_on_answer_space]]
- [[leetcode/0153-find-minimum-in-rotated-sorted-array/NOTES|0153-find-minimum-in-rotated-sorted-array]]: both show [[binary_search_on_answer_space]]
- [[leetcode/0875-koko-eating-bananas/NOTES|0875-koko-eating-bananas]]: both show [[binary_search_on_answer_space]]
- [[leetcode/3899-angles-of-a-triangle/NOTES|3899-angles-of-a-triangle]]: both show [[binary_search_on_answer_space]]

### Signals
- comment explicitly contrasts brute force `O((max-min)*n)` with binary search `O(log(max-min)*n)`, showing the solver reasoned about the search space
- comment 'left = min works because at least min days HAVE TO pass until we start counting' suggests the solver paused to justify the lower bound
