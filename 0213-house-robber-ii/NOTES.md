---
problem_id: '0213'
platform: 'leetcode'
title: 'House Robber II'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0213-house-robber-ii'
primary_tags:
  - '[[dp]]'
subtle_tags:
  - '[[subproblem_independence_recognition]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
  - '[[leetcode/0105-construct-binary-tree-from-preorder-and-inorder-traversal/NOTES|0105-construct-binary-tree-from-preorder-and-inorder-traversal]]'
  - '[[leetcode/0124-binary-tree-maximum-path-sum/NOTES|0124-binary-tree-maximum-path-sum]]'
  - '[[leetcode/0312-burst-balloons/NOTES|0312-burst-balloons]]'
---

## Explanations

No stronger latent-friction inference is supported beyond the current comments and prior notes.

### Subtle Tags
- [[subproblem_independence_recognition]]: the critical realization that decomposed subproblems share no state, enabling clean memoization — often the hardest insight in interval/partition DP

### Related Reasoning
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[subproblem_independence_recognition]]
- [[leetcode/0105-construct-binary-tree-from-preorder-and-inorder-traversal/NOTES|0105-construct-binary-tree-from-preorder-and-inorder-traversal]]: both show [[subproblem_independence_recognition]]
- [[leetcode/0124-binary-tree-maximum-path-sum/NOTES|0124-binary-tree-maximum-path-sum]]: both show [[subproblem_independence_recognition]]
- [[leetcode/0312-burst-balloons/NOTES|0312-burst-balloons]]: both show [[subproblem_independence_recognition]]

### Signals
- Comment: `same as house-robber / just do it once from 0 to n-1 and once from 1 to n and take max`
