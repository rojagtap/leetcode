---
problem_id: '0169'
platform: 'leetcode'
title: 'Majority Element'
difficulty: 'easy'
language: 'cpp'
aliases:
  - '0169-majority-element'
primary_tags:
  - '[[greedy]]'
  - '[[majority-vote]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[proof_gap]]'
related:
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/0332-reconstruct-itinerary/NOTES|0332-reconstruct-itinerary]]'
  - '[[leetcode/1584-min-cost-to-connect-all-points/NOTES|1584-min-cost-to-connect-all-points]]'
---

## Explanations

The likely sticking point is the cancellation invariant, not the algorithm name. The solver appears to have needed to convince themselves that pairing off mismatches cannot eliminate the true majority from eventual contention, so count-zero resets are safe.

### Mistake Notes
- [[proof_gap]]: Extended comment justifying why the algorithm works ('it is guaranteed to come across this element') suggests the correctness proof needed explicit reasoning

### Related Reasoning
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both notes focus on why a very small local certificate is enough for global correctness, so the shared issue is [[proof_gap]] rather than implementation
- [[leetcode/0332-reconstruct-itinerary/NOTES|0332-reconstruct-itinerary]]: both use a locally destructive step and then spend comments proving it does not destroy the global answer, which is shared [[proof_gap]]
- [[leetcode/1584-min-cost-to-connect-all-points/NOTES|1584-min-cost-to-connect-all-points]]: both solutions are standard, but the comments mostly justify why the canonical greedy rule is valid in this setting, a shared [[proof_gap]]

### Signals
- Comment: the count of the majority element can go 0 but will show up again as it appears more than $n/2$ times
- Comment: it will still be there at the last mismatch because it appears at least $n/2$ times
