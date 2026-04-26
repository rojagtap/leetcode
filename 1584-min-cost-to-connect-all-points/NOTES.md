---
problem_id: '1584'
platform: 'leetcode'
title: 'Min Cost to Connect All Points'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '1584-min-cost-to-connect-all-points'
primary_tags:
  - '[[greedy]]'
  - '[[minimum-spanning-tree]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[proof_gap]]'
related:
  - '[[leetcode/0169-majority-element/NOTES|0169-majority-element]]'
  - '[[leetcode/0332-reconstruct-itinerary/NOTES|0332-reconstruct-itinerary]]'
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
---

## Explanations

The likely sticking point is not MST syntax but selecting the right canonical frame for a dense complete graph. The long Prim-vs-Kruskal comparison suggests the solver needed to certify why the complete-graph structure makes the $O(V^2)$ Prim formulation the right fit here.

### Mistake Notes
- [[proof_gap]]: lengthy comment justifying Prim's over Kruskal's based on $E = V^2$, suggests the solver needed to reason through algorithm selection rather than having it fluent

### Related Reasoning
- [[leetcode/0169-majority-element/NOTES|0169-majority-element]]: both comments spend more effort justifying why the canonical greedy rule is safe than on the implementation itself, which is shared [[proof_gap]]
- [[leetcode/0332-reconstruct-itinerary/NOTES|0332-reconstruct-itinerary]]: both notes are really about certifying why a local choice rule does not spoil the global answer, a shared [[proof_gap]]
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: both solutions are accompanied by narrow correctness certificates, so the common difficulty is [[proof_gap]] around why a small condition is sufficient

### Signals
- comment block explains both Prim's and Kruskal's algorithms with complexity analysis before choosing
- in cases where $V \gg E$, we use Kruskal's, whereas if $E \gg V$, we use Prim's -- explicit decision heuristic written out
- in this case, $E = V^2$, so we will use Prim's -- final justification for the choice
- comment `all vertices have the same adjacency, except itself` notes the complete-graph property that simplifies the implementation
