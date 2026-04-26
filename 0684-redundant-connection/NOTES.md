---
problem_id: '0684'
platform: 'leetcode'
title: 'Redundant Connection'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0684-redundant-connection'
primary_tags:
  - '[[union-find]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The level of detail in the comments -- tracing the disjoint set array through every edge insertion -- suggests union-find was not yet fluent for the solver. The YouTube reference confirms this was likely a learning exercise. The implementation uses weighted union (merging smaller into larger) but does not use path compression, which is consistent with learning the algorithm incrementally.

### Signals
- Extensive comment walks through union-find from scratch with a full worked example including array state at each step
- References a YouTube video for union join
- 'think about it, there is an existing structure of this graph which connects all the vertices (undirected), if we create a bypass between any 2 nodes, this will form a cycle'
