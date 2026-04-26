---
problem_id: '0105'
platform: 'leetcode'
title: 'Construct Binary Tree from Preorder and Inorder Traversal'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0105-construct-binary-tree-from-preorder-and-inorder-traversal'
primary_tags:
  - '[[binary-tree]]'
  - '[[divide-and-conquer]]'
subtle_tags:
  - '[[flatten_tree_to_sequence]]'
  - '[[subproblem_independence_recognition]]'
candidate_tags: []
mistakes:
  - '[[micro_hesitation]]'
related:
  - '[[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]'
  - '[[leetcode/0098-validate-binary-search-tree/NOTES|0098-validate-binary-search-tree]]'
  - '[[leetcode/0106-construct-binary-tree-from-inorder-and-postorder-traversal/NOTES|0106-construct-binary-tree-from-inorder-and-postorder-traversal]]'
  - '[[leetcode/0124-binary-tree-maximum-path-sum/NOTES|0124-binary-tree-maximum-path-sum]]'
  - '[[leetcode/0213-house-robber-ii/NOTES|0213-house-robber-ii]]'
---

## Explanations

The solver appears to have needed to carefully reason through the relationship between preorder and inorder sequences -- the comment block works through a concrete example of how the root index in inorder partitions left/right subtrees. The key insight is that each recursive subproblem operates on independent inorder ranges, with preorder providing the root identity.

### Subtle Tags
- [[flatten_tree_to_sequence]]: leveraging that a specific traversal order of a tree maps to a well-understood sequence property (inorder BST = sorted array)
- [[subproblem_independence_recognition]]: the critical realization that decomposed subproblems share no state, enabling clean memoization — often the hardest insight in interval/partition DP

### Mistake Notes
- [[micro_hesitation]]: Extensive comment explaining how preorder gives roots and inorder gives subtree ranges suggests the mapping between traversal arrays and tree structure required careful working-through

### Related Reasoning
- [[leetcode/0062-unique-paths/NOTES|0062-unique-paths]]: both show [[subproblem_independence_recognition]]
- [[leetcode/0098-validate-binary-search-tree/NOTES|0098-validate-binary-search-tree]]: both show [[flatten_tree_to_sequence]]
- [[leetcode/0106-construct-binary-tree-from-inorder-and-postorder-traversal/NOTES|0106-construct-binary-tree-from-inorder-and-postorder-traversal]]: both show [[flatten_tree_to_sequence]]
- [[leetcode/0124-binary-tree-maximum-path-sum/NOTES|0124-binary-tree-maximum-path-sum]]: both show [[subproblem_independence_recognition]]
- [[leetcode/0213-house-robber-ii/NOTES|0213-house-robber-ii]]: both show [[subproblem_independence_recognition]]

### Signals
- Long block comment walking through how `preorder[0]` will always be the root and `inorder[0-2]` will be the left subtree
- Explicit naming of `leftbound`/`rightbound` with comments explaining what they represent
