---
problem_id: '0239'
platform: 'leetcode'
title: 'Sliding Window Maximum'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0239-sliding-window-maximum'
primary_tags:
  - '[[monotonic-deque]]'
  - '[[sliding-window]]'
subtle_tags:
  - '[[monotonic_structure_exploitation]]'
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related:
  - '[[leetcode/0084-largest-rectangle-in-histogram/NOTES|0084-largest-rectangle-in-histogram]]'
  - '[[leetcode/0023-merge-k-sorted-lists/NOTES|0023-merge-k-sorted-lists]]'
  - '[[leetcode/0155-min-stack/NOTES|0155-min-stack]]'
  - '[[leetcode/0739-daily-temperatures/NOTES|0739-daily-temperatures]]'
  - '[[leetcode/1851-minimum-interval-to-include-each-query/NOTES|1851-minimum-interval-to-include-each-query]]'
---

## Explanations

The comments show a clear progression from a naive single-max tracker to the monotonic deque. The solver likely struggled with the case where the current maximum exits the window, which motivated the decreasing-order invariant. The key insight -- that maintaining a monotone structure gives amortized `O(1)` access to the next-best candidate -- appears to have been arrived at through reasoning about what information is lost when `max` leaves.

### Subtle Tags
- [[monotonic_structure_exploitation]]: recognizing that maintaining a sorted/monotone invariant in a data structure provides amortized `O(1)` for queries that would otherwise require rescanning

### Mistake Notes
- [[wrong_path]]: initially considered tracking a single maxelement int, then identified the failure when max leaves the window

### Related Reasoning
- [[leetcode/0084-largest-rectangle-in-histogram/NOTES|0084-largest-rectangle-in-histogram]]: both show [[monotonic_structure_exploitation]] with shared [[wrong_path]]
- [[leetcode/0023-merge-k-sorted-lists/NOTES|0023-merge-k-sorted-lists]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0155-min-stack/NOTES|0155-min-stack]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0739-daily-temperatures/NOTES|0739-daily-temperatures]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/1851-minimum-interval-to-include-each-query/NOTES|1851-minimum-interval-to-include-each-query]]: both show [[monotonic_structure_exploitation]]

### Signals
- Comment describes naive approach: 'have a window of size k and keep a maxelement int'
- 'the problem with this approach comes when the element leaving the window is maxelement and the new element coming in is not'
- Explicitly reasons toward needing 'the second best element in the window to replace the maxelement when it leaves'
