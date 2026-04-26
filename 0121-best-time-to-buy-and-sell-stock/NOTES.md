---
problem_id: '0121'
platform: 'leetcode'
title: 'Best Time to Buy and Sell Stock'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '0121-best-time-to-buy-and-sell-stock'
primary_tags:
  - '[[two-pointer]]'
subtle_tags:
  - '[[prefix_suffix_decomposition]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/3901-good-subsequence-queries/NOTES|3901-good-subsequence-queries]]'
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0238-product-of-array-except-self/NOTES|0238-product-of-array-except-self]]'
  - '[[leetcode/3900-longest-balanced-substring-after-one-swap/NOTES|3900-longest-balanced-substring-after-one-swap]]'
---

## Explanations

The solver likely first built a suffix-max solution decomposing the problem into a prefix pass (buy) and suffix pass (sell), then recognized the suffix array was unnecessary since a single left-to-right pass tracking the running minimum achieves the same result.

### Subtle Tags
- [[prefix_suffix_decomposition]]: decomposing a problem into prefix and suffix passes, where each pass carries cumulative information the other needs

### Mistake Notes
- [[wrong_path]]: First approach used suffix-max array (`O(n)` space), then rewrote as single-pass sliding window (`O(1)` space)

### Related Reasoning
- [[leetcode/3901-good-subsequence-queries/NOTES|3901-good-subsequence-queries]]: both show [[prefix_suffix_decomposition]] with shared [[wrong_path]]
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both show [[prefix_suffix_decomposition]]
- [[leetcode/0238-product-of-array-except-self/NOTES|0238-product-of-array-except-self]]: both show [[prefix_suffix_decomposition]]
- [[leetcode/3900-longest-balanced-substring-after-one-swap/NOTES|3900-longest-balanced-substring-after-one-swap]]: both show [[prefix_suffix_decomposition]]

### Signals
- Commented-out `suffix max solution` with a two-pass approach
- Active solution described as `sliding window` with `left = buy`, `right = sell`
