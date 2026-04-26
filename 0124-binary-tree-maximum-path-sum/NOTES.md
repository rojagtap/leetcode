---
problem_id: '0124'
platform: 'leetcode'
title: 'Binary Tree Maximum Path Sum'
difficulty: 'hard'
language: 'cpp'
aliases:
  - '0124-binary-tree-maximum-path-sum'
primary_tags:
  - '[[binary-tree]]'
subtle_tags:
  - '[[subproblem_independence_recognition]]'
candidate_tags: []
mistakes:
  - '[[proof_gap]]'
related:
  - '[[leetcode/0312-burst-balloons/NOTES|0312-burst-balloons]]'
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
  - '[[leetcode/0105-construct-binary-tree-from-preorder-and-inorder-traversal/NOTES|0105-construct-binary-tree-from-preorder-and-inorder-traversal]]'
  - '[[leetcode/0213-house-robber-ii/NOTES|0213-house-robber-ii]]'
  - '[[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]'
---

## Explanations

The critical subtlety is that the global answer can include both children (forming a path through the node), but the value returned to the parent can only include one branch. The "selective" comment suggests the solver needed to reason carefully about which combinations form valid paths versus which are just locally optimal sums.

### Subtle Tags
- [[subproblem_independence_recognition]]: the critical realization that decomposed subproblems share no state, enabling clean memoization — often the hardest insight in interval/partition DP

### Mistake Notes
- [[proof_gap]]: Comment distinguishes 'max can be selective' from simple subtree sum -- the four-way max suggests working through which combinations are valid paths

### Related Reasoning
- [[leetcode/0312-burst-balloons/NOTES|0312-burst-balloons]]: both show [[subproblem_independence_recognition]] with shared [[proof_gap]]
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[subproblem_independence_recognition]]
- [[leetcode/0105-construct-binary-tree-from-preorder-and-inorder-traversal/NOTES|0105-construct-binary-tree-from-preorder-and-inorder-traversal]]: both show [[subproblem_independence_recognition]]
- [[leetcode/0213-house-robber-ii/NOTES|0213-house-robber-ii]]: both show [[subproblem_independence_recognition]]
- [[leetcode/0004-median-of-two-sorted-arrays/NOTES|0004-median-of-two-sorted-arrays]]: shared [[proof_gap]] pattern

### Signals
- Comment: `similar to taking subtree sum but the max can be selective i.e. max(node, left + node, right + node, left + right + node)`
- Return value differs from update: maxsum considers all four combos but return only allows single-branch paths
