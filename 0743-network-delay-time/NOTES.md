---
problem_id: '0743'
platform: 'leetcode'
title: 'Network Delay Time'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0743-network-delay-time'
primary_tags:
  - '[[dijkstra]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The solver annotates two subtle Dijkstra implementation details: why a visited set is not strictly needed (the relaxation condition already skips suboptimal re-processing), and why stale heap entries must be handled. These comments suggest the solver was reasoning carefully about correctness rather than applying Dijkstra's mechanically.

### Signals
- Comment explains why visited is unnecessary in Dijkstra's: `the basic assumption of Dijkstra's is if we traverse the shortest path from A -> D via B then B -> D will also be the shortest path from B`
- Comment on heap duplicates: `because heap has duplicates contrary to mintime which overwrites the shortest path for each vertex`
