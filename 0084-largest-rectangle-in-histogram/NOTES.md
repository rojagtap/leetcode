---
problem_id: '0084'
platform: 'leetcode'
title: 'Largest Rectangle in Histogram'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0084-largest-rectangle-in-histogram'
primary_tags:
  - '[[monotonic-stack]]'
subtle_tags:
  - '[[monotonic_structure_exploitation]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0239-sliding-window-maximum/NOTES|0239-sliding-window-maximum]]'
  - '[[leetcode/0023-merge-k-sorted-lists/NOTES|0023-merge-k-sorted-lists]]'
  - '[[leetcode/0155-min-stack/NOTES|0155-min-stack]]'
  - '[[leetcode/0739-daily-temperatures/NOTES|0739-daily-temperatures]]'
  - '[[leetcode/1851-minimum-interval-to-include-each-query/NOTES|1851-minimum-interval-to-include-each-query]]'
---

## Explanations

The solver progressed through three approaches with increasing sophistication. The key insight in the single-pass version -- that when popping, the current element is the right boundary and the new top is the left boundary -- is explained in detail, suggesting it required careful reasoning. The monotonic stack invariant (stack always holds indices in increasing height order) is what makes both boundaries available at pop time.

### Subtle Tags
- [[monotonic_structure_exploitation]]: recognizing that maintaining a sorted/monotone invariant in a data structure provides amortized `O(1)` for queries that would otherwise require rescanning

### Mistake Notes
- [[wrong_path]]: three approaches preserved: brute force `O(n^2)`, two-pass monotonic stack with separate `leftsmall`/`rightsmall` arrays, single-pass monotonic stack

### Related Reasoning
- [[leetcode/0239-sliding-window-maximum/NOTES|0239-sliding-window-maximum]]: both show [[monotonic_structure_exploitation]] with shared [[wrong_path]]
- [[leetcode/0023-merge-k-sorted-lists/NOTES|0023-merge-k-sorted-lists]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0155-min-stack/NOTES|0155-min-stack]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0739-daily-temperatures/NOTES|0739-daily-temperatures]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/1851-minimum-interval-to-include-each-query/NOTES|1851-minimum-interval-to-include-each-query]]: both show [[monotonic_structure_exploitation]]

### Signals
- Approach 3: Optimal
- in the previous approach, we calculated the left and right smaller values for each `heights[i]`
- however, we can solve this using just 1 pass and without using 2 separate arrays
- whenever `heights[i] < stack.top()`, `heights[i]` becomes the `rightsmall` of `stack.top()`
- also, `stack[-2]` becomes the `leftsmall` for `stack.top()` because we pushed `stack.top()` only when it was `> stack[-2]`
- this is again `O(n)` time and `O(n)` space, but done in one pass
- three full approaches preserved with detailed commentary
