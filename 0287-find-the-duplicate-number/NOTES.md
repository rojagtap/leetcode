---
problem_id: '0287'
platform: 'leetcode'
title: 'Find the Duplicate Number'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0287-find-the-duplicate-number'
primary_tags:
  - '[[two-pointer]]'
subtle_tags:
  - '[[cycle_detection_as_function_graph]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0141-linked-list-cycle/NOTES|0141-linked-list-cycle]]'
  - '[[leetcode/0202-happy-number/NOTES|0202-happy-number]]'
---

## Explanations

The solver systematically narrows the approach based on constraints, arriving at Floyd's cycle detection. The comment explicitly connects the array-as-pointer abstraction to cycle formation, which is the critical representation shift for this problem. The enumeration of alternatives suggests the solver needed to reason through why simpler approaches are disallowed before committing to Floyd's.

### Subtle Tags
- [[cycle_detection_as_function_graph]]: recognizing that array-as-pointer or numeric iteration creates a functional graph where Floyd's cycle detection applies

### Related Reasoning
- [[leetcode/0141-linked-list-cycle/NOTES|0141-linked-list-cycle]]: both show [[cycle_detection_as_function_graph]]
- [[leetcode/0202-happy-number/NOTES|0202-happy-number]]: both show [[cycle_detection_as_function_graph]]

### Signals
- Comment enumerates three approaches by constraint: if `O(n)` space is allowed, use hash; if modifying the array is allowed, use visited flags `-1`; if nothing is allowed, use `Floyd's`
- 'if we use elements as index numbers to other elements, then there will be two elements that point to the same index as there is a repetition, hence, cycle'
