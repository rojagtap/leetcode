---
problem_id: '0153'
platform: 'leetcode'
title: 'Find Minimum in Rotated Sorted Array'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0153-find-minimum-in-rotated-sorted-array'
primary_tags:
  - '[[binary-search]]'
subtle_tags:
  - '[[binary_search_on_answer_space]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/0875-koko-eating-bananas/NOTES|0875-koko-eating-bananas]]'
  - '[[leetcode/1482-minimum-number-of-days-to-make-m-bouquets/NOTES|1482-minimum-number-of-days-to-make-m-bouquets]]'
  - '[[leetcode/3899-angles-of-a-triangle/NOTES|3899-angles-of-a-triangle]]'
---

## Explanations

No stronger latent-friction inference is supported beyond the current comments and prior notes.

### Subtle Tags
- [[binary_search_on_answer_space]]: recognizing that the answer itself is monotone and searchable rather than searching the input directly

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both show [[binary_search_on_answer_space]]
- [[leetcode/0875-koko-eating-bananas/NOTES|0875-koko-eating-bananas]]: both show [[binary_search_on_answer_space]]
- [[leetcode/1482-minimum-number-of-days-to-make-m-bouquets/NOTES|1482-minimum-number-of-days-to-make-m-bouquets]]: both show [[binary_search_on_answer_space]]
- [[leetcode/3899-angles-of-a-triangle/NOTES|3899-angles-of-a-triangle]]: both show [[binary_search_on_answer_space]]

### Signals
- Comment: if `arr[mid] > arr[0]`, then we try to the right if we can find anything bigger -- binary search finds the max, then returns `max + 1` as the min
