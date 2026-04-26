---
problem_id: '1851'
platform: 'leetcode'
title: 'Minimum Interval to Include Each Query'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '1851-minimum-interval-to-include-each-query'
primary_tags:
  - '[[sorting]]'
  - '[[heap]]'
subtle_tags:
  - '[[monotonic_structure_exploitation]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0023-merge-k-sorted-lists/NOTES|0023-merge-k-sorted-lists]]'
  - '[[leetcode/0084-largest-rectangle-in-histogram/NOTES|0084-largest-rectangle-in-histogram]]'
  - '[[leetcode/0155-min-stack/NOTES|0155-min-stack]]'
  - '[[leetcode/0239-sliding-window-maximum/NOTES|0239-sliding-window-maximum]]'
  - '[[leetcode/0739-daily-temperatures/NOTES|0739-daily-temperatures]]'
---

## Explanations

The solver's comment block is detailed but appears to be a plan written before coding rather than evidence of struggle. The key insight -- that sorting queries allows permanent eviction of intervals whose end falls before the current query -- is articulated inline, suggesting the solver recognized the monotonic_structure_exploitation that makes the sweep-line approach work.

### Subtle Tags
- [[monotonic_structure_exploitation]]: recognizing that maintaining a sorted/monotone invariant in a data structure provides amortized `O(1)` for queries that would otherwise require rescanning

### Related Reasoning
- [[leetcode/0023-merge-k-sorted-lists/NOTES|0023-merge-k-sorted-lists]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0084-largest-rectangle-in-histogram/NOTES|0084-largest-rectangle-in-histogram]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0155-min-stack/NOTES|0155-min-stack]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0239-sliding-window-maximum/NOTES|0239-sliding-window-maximum]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0739-daily-temperatures/NOTES|0739-daily-temperatures]]: both show [[monotonic_structure_exploitation]]

### Signals
- comment walks through the full sweep-line strategy step by step: sort intervals, sort queries, push to heap, pop expired
- 'pop out all the heap tops where the end < query (i.e., all the intervals not consisting the query. now since query is sorted, these intervals are anyway not going to be used)' -- explicitly justifies why expired intervals can be discarded permanently
