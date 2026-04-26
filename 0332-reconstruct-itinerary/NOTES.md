---
problem_id: '0332'
platform: 'leetcode'
title: 'Reconstruct Itinerary'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0332-reconstruct-itinerary'
primary_tags:
  - '[[graph-dfs]]'
  - '[[eulerian-path]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[proof_gap]]'
related:
  - '[[leetcode/0169-majority-element/NOTES|0169-majority-element]]'
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
  - '[[leetcode/1584-min-cost-to-connect-all-points/NOTES|1584-min-cost-to-connect-all-points]]'
---

## Explanations

The hidden obstacle is not DFS syntax; it is certifying why consuming an edge now is safe only because the route is being assembled in reverse postorder. The comments show friction around edge identity in a multigraph, but the deeper proof burden is why destructive edge use still yields the lexicographically smallest valid Eulerian path.

### Mistake Notes
- [[proof_gap]]: comments reason about why visited sets fail for multigraphs but the connection to Hierholzer's algorithm is implicit

### Related Reasoning
- [[leetcode/0169-majority-element/NOTES|0169-majority-element]]: both contain a locally destructive update whose safety has to be justified globally, so the shared issue is [[proof_gap]] around the invariant, not the implementation
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both comments narrow correctness to a small local condition that certifies the whole answer, which is shared [[proof_gap]]
- [[leetcode/1584-min-cost-to-connect-all-points/NOTES|1584-min-cost-to-connect-all-points]]: both are standard algorithms where the solver seems more occupied with why the canonical rule applies here than with how to code it, a shared [[proof_gap]]

### Signals
- 'visited sets wont help as there can be multiple A to B edges'
- 'even if you use multisets, you cannot tell which one is visited'
- 'popping from front ensures that the edge isnt available for any other traversals hence simulating visited'
