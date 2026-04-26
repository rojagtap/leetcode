---
problem_id: '3901'
platform: 'leetcode'
title: 'Good Subsequence Queries'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '3901-good-subsequence-queries'
primary_tags:
  - '[[hashmap]]'
  - '[[gcd]]'
subtle_tags:
  - '[[prefix_suffix_decomposition]]'
  - '[[all_or_all_but_one_case_split]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0121-best-time-to-buy-and-sell-stock/NOTES|0121-best-time-to-buy-and-sell-stock]]'
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0238-product-of-array-except-self/NOTES|0238-product-of-array-except-self]]'
  - '[[leetcode/3900-longest-balanced-substring-after-one-swap/NOTES|3900-longest-balanced-substring-after-one-swap]]'
---

## Explanations

The commented-out brute-force exclude-one loop is a clear signal the solver first wrote the `O(n^2)` path, then recognized the prefix-suffix optimization. The deeper reusable pattern is the case split itself: once the reasoning narrows the search to "all eligible elements" versus "all but one eligible element," the prefix/suffix machinery becomes inevitable.

### Subtle Tags
- [[prefix_suffix_decomposition]]: decomposing a problem into prefix and suffix passes, where each pass carries cumulative information the other needs
- [[all_or_all_but_one_case_split]]: the constraint only bites when the optimum uses every eligible element, so the search collapses to the full set versus exclude-one candidates

### Mistake Notes
- [[wrong_path]]: commented-out `O(n^2)` exclude-one-element loop replaced by prefix-suffix GCD decomposition, suggesting the brute force was written first

### Related Reasoning
- [[leetcode/0121-best-time-to-buy-and-sell-stock/NOTES|0121-best-time-to-buy-and-sell-stock]]: both start with a slower recomputation mindset and then realize each answer only needs aggregate information from the complement, so they share [[prefix_suffix_decomposition]] with [[wrong_path]]
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both precompute left and right summaries so each local decision can be made without rescanning the rest, which is shared [[prefix_suffix_decomposition]]
- [[leetcode/0238-product-of-array-except-self/NOTES|0238-product-of-array-except-self]]: both answer an all-except-one aggregate query by joining prefix and suffix state instead of recomputing from scratch, a clean instance of [[prefix_suffix_decomposition]]
- [[leetcode/3900-longest-balanced-substring-after-one-swap/NOTES|3900-longest-balanced-substring-after-one-swap]]: both rely on left and right summary passes to repair a direct approach that was too local, which is shared [[prefix_suffix_decomposition]]

### Signals
- commented-out nested loop shows the abandoned `O(n^2)` path:

  ```cpp
  for (auto& [exclude, _] : freq) {
    ...
    for (auto& [num, count] : freq) {
      if (num == exclude) continue;
      ...
    }
  }
  ```

- the note immediately follows it by claiming the same can be achieved in `O(n)` using prefix-suffix GCD
- comment `if there are less than n p-divisible numbers we already know p is a common factor` -- reasoning about when full-set GCD suffices vs needing exclude-one
- comment `we want to remove other factors, so for gcd, more the merrier` -- informal justification for the check-all-vs-exclude-one branching
