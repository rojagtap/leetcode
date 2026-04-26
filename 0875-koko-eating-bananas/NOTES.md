---
problem_id: '0875'
platform: 'leetcode'
title: 'Koko Eating Bananas'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0875-koko-eating-bananas'
primary_tags:
  - '[[binary-search]]'
subtle_tags:
  - '[[binary_search_on_answer_space]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/0153-find-minimum-in-rotated-sorted-array/NOTES|0153-find-minimum-in-rotated-sorted-array]]'
  - '[[leetcode/1482-minimum-number-of-days-to-make-m-bouquets/NOTES|1482-minimum-number-of-days-to-make-m-bouquets]]'
  - '[[leetcode/3899-angles-of-a-triangle/NOTES|3899-angles-of-a-triangle]]'
---

## Explanations

The comment block walks through the guess-and-check reasoning before arriving at binary search, which suggests the solver likely internalized the binary_search_on_answer_space pattern here. The implementation is clean with no wrong paths visible.

### Subtle Tags
- [[binary_search_on_answer_space]]: recognizing that the answer itself is monotone and searchable rather than searching the input directly

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both show [[binary_search_on_answer_space]]
- [[leetcode/0153-find-minimum-in-rotated-sorted-array/NOTES|0153-find-minimum-in-rotated-sorted-array]]: both show [[binary_search_on_answer_space]]
- [[leetcode/1482-minimum-number-of-days-to-make-m-bouquets/NOTES|1482-minimum-number-of-days-to-make-m-bouquets]]: both show [[binary_search_on_answer_space]]
- [[leetcode/3899-angles-of-a-triangle/NOTES|3899-angles-of-a-triangle]]: both show [[binary_search_on_answer_space]]

### Signals
- comment 'guess a speed' and 'here for guessing, we use binary search' suggests the solver explicitly articulated the guess-and-check framing before recognizing binary search applies
