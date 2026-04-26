---
problem_id: '3912'
platform: 'leetcode'
title: 'Valid Elements in an Array'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '3912-valid-elements-in-an-array'
primary_tags:
  - '[[prefix-sum]]'
subtle_tags:
  - '[[prefix_suffix_decomposition]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]'
  - '[[leetcode/0238-product-of-array-except-self/NOTES|0238-product-of-array-except-self]]'
  - '[[leetcode/3901-good-subsequence-queries/NOTES|3901-good-subsequence-queries]]'
---

## Explanations

`no_signal`. Clean direct application of [[prefix_suffix_decomposition]]: precompute strict-suffix max in one reverse pass, then sweep left tracking the strict-prefix max and accept `nums[i]` if it beats either. No comments, no abandoned code, no friction artifacts in the source. Recorded only so the canonical prefix/suffix pattern stays connected in the graph.

### Subtle Tags
- [[prefix_suffix_decomposition]]: decomposing a problem into prefix and suffix passes, where each pass carries cumulative information the other needs

### Related Reasoning
- [[leetcode/0042-trapping-rain-water/NOTES|0042-trapping-rain-water]]: both show [[prefix_suffix_decomposition]] where each position needs a left-side and right-side aggregate (max here, max there)
- [[leetcode/0238-product-of-array-except-self/NOTES|0238-product-of-array-except-self]]: both show [[prefix_suffix_decomposition]] where the answer at `i` is built from a prefix aggregate and a suffix aggregate computed independently
- [[leetcode/3901-good-subsequence-queries/NOTES|3901-good-subsequence-queries]]: both show [[prefix_suffix_decomposition]] for an "is this index special" question that decomposes into independent left and right summaries

### Signals
- single source file, no comments and no commented-out code -- consistent with a one-shot direct solve
- the strict-prefix max is maintained inline (`leftmax = max(leftmax, nums[i])` after the check) so the comparison sees the max over `[0, i)` only; same trick on the suffix pass
