---
problem_id: '0199'
platform: 'leetcode'
title: 'Binary Tree Right Side View'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0199-binary-tree-right-side-view'
primary_tags:
  - '[[binary-tree]]'
  - '[[graph-bfs]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[wrong_path]]'
related: []
---

## Explanations

The solver initially misread the problem as "traverse the right spine" and constructed a counterexample tree to disprove it. The correction to level-order BFS with last-element-per-level extraction follows naturally once the problem is properly understood.

### Mistake Notes
- [[wrong_path]]: Initially considered following `right->right->right`, then realized `Right Side View` means the rightmost node per level, not just the right chain

### Signals
- Comment: `why not go right->right->right?` followed by a counterexample tree where left child 4 is visible from the right
- Comment: `basically Right Side View means the actual right side view, i.e., rightmost element on each level / so level order traversal`
