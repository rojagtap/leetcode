---
problem_id: '3899'
platform: 'leetcode'
title: 'Angles of a Triangle'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '3899-angles-of-a-triangle'
primary_tags:
  - '[[binary-search]]'
subtle_tags:
  - '[[binary_search_on_answer_space]]'
candidate_tags: []
mistakes:
  - '[[knowledge_gap]]'
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/0153-find-minimum-in-rotated-sorted-array/NOTES|0153-find-minimum-in-rotated-sorted-array]]'
  - '[[leetcode/0875-koko-eating-bananas/NOTES|0875-koko-eating-bananas]]'
  - '[[leetcode/1482-minimum-number-of-days-to-make-m-bouquets/NOTES|1482-minimum-number-of-days-to-make-m-bouquets]]'
  - '[[leetcode/3934-smallest-unique-subarray/NOTES|3934-smallest-unique-subarray]]'
---

## Explanations

The explicit link to an external solution suggests the solver likely studied this approach rather than deriving it independently. The detailed inline comments about the perpendicular landing on the base (not outside) indicate the solver needed to work through the geometric reasoning carefully to understand why the binary search on angle works.

### Subtle Tags
- [[binary_search_on_answer_space]]: recognizing that the answer itself is monotone and searchable rather than searching the input directly

### Mistake Notes
- [[knowledge_gap]]: references external solution link, suggesting the binary-search-on-angle approach was not self-derived

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both show [[binary_search_on_answer_space]]
- [[leetcode/0153-find-minimum-in-rotated-sorted-array/NOTES|0153-find-minimum-in-rotated-sorted-array]]: both show [[binary_search_on_answer_space]]
- [[leetcode/0875-koko-eating-bananas/NOTES|0875-koko-eating-bananas]]: both show [[binary_search_on_answer_space]]
- [[leetcode/1482-minimum-number-of-days-to-make-m-bouquets/NOTES|1482-minimum-number-of-days-to-make-m-bouquets]]: both show [[binary_search_on_answer_space]]
- [[leetcode/3934-smallest-unique-subarray/NOTES|3934-smallest-unique-subarray]]: both show [[binary_search_on_answer_space]] with shared [[knowledge_gap]] on the inner-loop technique — the answer-axis monotonicity is the right framing in both, and in both the inner-step technique was reached for from an external reference rather than self-derived

### Signals
- comment links to external solution: 'https://leetcode.com/problems/angles-of-a-triangle/solutions/7877131/binary-search-without-using-formulas-by-46k3z'
- comment 'this ensures the top vertex is the largest angle which means the perpendicular will always be on the base (not outside)' -- geometric invariant spelled out in detail
