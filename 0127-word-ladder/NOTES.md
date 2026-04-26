---
problem_id: '0127'
platform: 'leetcode'
title: 'Word Ladder'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0127-word-ladder'
primary_tags:
  - '[[graph-bfs]]'
  - '[[hashmap]]'
subtle_tags: []
candidate_tags: []
mistakes: []
related: []
---

## Explanations

The notable signal here is the concrete wildcard-bucket construction and the choice to run BFS from `endWord`, not a reusable latent-friction pattern. That makes it better as evidence in the note than as a candidate ontology tag.

### Signals
- Detailed comment describing the wildcard-pattern adjacency construction:

  ```text
  _ot: [hot, dot, lot]
  ```
- BFS starts from `endWord` and checks against `beginWord`'s neighbor set -- reverse direction choice
