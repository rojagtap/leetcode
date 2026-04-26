---
problem_id: '0023'
platform: 'leetcode'
title: 'Merge K Sorted Lists'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0023-merge-k-sorted-lists'
primary_tags:
  - '[[heap]]'
  - '[[linked-list]]'
subtle_tags:
  - '[[monotonic_structure_exploitation]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0084-largest-rectangle-in-histogram/NOTES|0084-largest-rectangle-in-histogram]]'
  - '[[leetcode/0155-min-stack/NOTES|0155-min-stack]]'
  - '[[leetcode/0239-sliding-window-maximum/NOTES|0239-sliding-window-maximum]]'
  - '[[leetcode/0739-daily-temperatures/NOTES|0739-daily-temperatures]]'
  - '[[leetcode/1851-minimum-interval-to-include-each-query/NOTES|1851-minimum-interval-to-include-each-query]]'
---

## Explanations

No stronger latent-friction inference is supported beyond the current comments and prior notes.

### Subtle Tags
- [[monotonic_structure_exploitation]]: recognizing that maintaining a sorted/monotone invariant in a data structure provides amortized `O(1)` for queries that would otherwise require rescanning

### Related Reasoning
- [[leetcode/0084-largest-rectangle-in-histogram/NOTES|0084-largest-rectangle-in-histogram]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0155-min-stack/NOTES|0155-min-stack]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0239-sliding-window-maximum/NOTES|0239-sliding-window-maximum]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0739-daily-temperatures/NOTES|0739-daily-temperatures]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/1851-minimum-interval-to-include-each-query/NOTES|1851-minimum-interval-to-include-each-query]]: both show [[monotonic_structure_exploitation]]
