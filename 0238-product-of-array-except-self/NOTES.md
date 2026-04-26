---
problem_id: '0238'
platform: 'leetcode'
title: 'Product of Array Except Self'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0238-product-of-array-except-self'
primary_tags:
  - '[[prefix-sum]]'
subtle_tags:
  - '[[prefix_suffix_decomposition]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0121-best-time-to-buy-and-sell-stock/NOTES|0121-best-time-to-buy-and-sell-stock]]'
  - '[[leetcode/3900-longest-balanced-substring-after-one-swap/NOTES|3900-longest-balanced-substring-after-one-swap]]'
  - '[[leetcode/3901-good-subsequence-queries/NOTES|3901-good-subsequence-queries]]'
---

## Explanations

The solver appears to have first arrived at the `O(n)`-space prefix/postfix solution, then worked through the `O(1)`-space variant separately. The comment quoting the follow-up question suggests the space optimization required deliberate reasoning about how to fold the postfix pass into the existing prefix array.

### Subtle Tags
- [[prefix_suffix_decomposition]]: decomposing a problem into prefix and suffix passes, where each pass carries cumulative information the other needs

### Related Reasoning
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both show [[prefix_suffix_decomposition]]
- [[leetcode/0121-best-time-to-buy-and-sell-stock/NOTES|0121-best-time-to-buy-and-sell-stock]]: both show [[prefix_suffix_decomposition]]
- [[leetcode/3900-longest-balanced-substring-after-one-swap/NOTES|3900-longest-balanced-substring-after-one-swap]]: both show [[prefix_suffix_decomposition]]
- [[leetcode/3901-good-subsequence-queries/NOTES|3901-good-subsequence-queries]]: both show [[prefix_suffix_decomposition]]

### Signals
- Comment walks through two-pass optimization: 'in the first pass, we do a prefix product directly in the return array and in the second pass, we directly multiply the postfix'
- Quotes the `O(1)`-space follow-up question verbatim, suggesting it was a friction point
