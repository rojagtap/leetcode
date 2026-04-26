---
problem_id: '0155'
platform: 'leetcode'
title: 'Min Stack'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0155-min-stack'
primary_tags:
  - '[[stack]]'
subtle_tags:
  - '[[monotonic_structure_exploitation]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0023-merge-k-sorted-lists/NOTES|0023-merge-k-sorted-lists]]'
  - '[[leetcode/0084-largest-rectangle-in-histogram/NOTES|0084-largest-rectangle-in-histogram]]'
  - '[[leetcode/0239-sliding-window-maximum/NOTES|0239-sliding-window-maximum]]'
  - '[[leetcode/0739-daily-temperatures/NOTES|0739-daily-temperatures]]'
  - '[[leetcode/1851-minimum-interval-to-include-each-query/NOTES|1851-minimum-interval-to-include-each-query]]'
---

## Explanations

No stronger latent-friction inference is supported beyond the current comments and prior notes.

### Subtle Tags
- [[monotonic_structure_exploitation]]: recognizing that maintaining a sorted/monotone invariant in a data structure provides amortized `O(1)` for queries that would otherwise require rescanning

### Related Reasoning
- [[leetcode/0023-merge-k-sorted-lists/NOTES|0023-merge-k-sorted-lists]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0084-largest-rectangle-in-histogram/NOTES|0084-largest-rectangle-in-histogram]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0239-sliding-window-maximum/NOTES|0239-sliding-window-maximum]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0739-daily-temperatures/NOTES|0739-daily-temperatures]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/1851-minimum-interval-to-include-each-query/NOTES|1851-minimum-interval-to-include-each-query]]: both show [[monotonic_structure_exploitation]]
