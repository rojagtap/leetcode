---
problem_id: '0739'
platform: 'leetcode'
title: 'Daily Temperatures'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0739-daily-temperatures'
primary_tags:
  - '[[monotonic-stack]]'
subtle_tags:
  - '[[monotonic_structure_exploitation]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0023-merge-k-sorted-lists/NOTES|0023-merge-k-sorted-lists]]'
  - '[[leetcode/0084-largest-rectangle-in-histogram/NOTES|0084-largest-rectangle-in-histogram]]'
  - '[[leetcode/0155-min-stack/NOTES|0155-min-stack]]'
  - '[[leetcode/0239-sliding-window-maximum/NOTES|0239-sliding-window-maximum]]'
  - '[[leetcode/1851-minimum-interval-to-include-each-query/NOTES|1851-minimum-interval-to-include-each-query]]'
---

## Explanations

The solver implements two distinct approaches. The reverse-scan solution exploits the already-computed daysUntilWarm to skip chains of smaller values, effectively using the result array as an implicit monotonic structure. The forward-scan monotonic stack is the more standard approach. The extensive step-by-step traces for both suggest the solver was building intuition for why the amortized cost remains linear despite the inner while loop.

### Subtle Tags
- [[monotonic_structure_exploitation]]: recognizing that maintaining a sorted/monotone invariant in a data structure provides amortized `O(1)` for queries that would otherwise require rescanning

### Related Reasoning
- [[leetcode/0023-merge-k-sorted-lists/NOTES|0023-merge-k-sorted-lists]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0084-largest-rectangle-in-histogram/NOTES|0084-largest-rectangle-in-histogram]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0155-min-stack/NOTES|0155-min-stack]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/0239-sliding-window-maximum/NOTES|0239-sliding-window-maximum]]: both show [[monotonic_structure_exploitation]]
- [[leetcode/1851-minimum-interval-to-include-each-query/NOTES|1851-minimum-interval-to-include-each-query]]: both show [[monotonic_structure_exploitation]]

### Signals
- Two complete approaches: reverse-scan with jump optimization and forward-scan monotonic stack
- Detailed trace of the reverse approach: `for any temperatures[i] >= temperatures[i + 1] we can skip all the temperatures[i + 1 + x] <= temperatures[i + 1]`
- Full step-by-step trace for both approaches with array state at each iteration
