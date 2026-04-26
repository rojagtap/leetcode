---
problem_id: '0106'
platform: 'leetcode'
title: 'Construct Binary Tree from Inorder and Postorder Traversal'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0106-construct-binary-tree-from-inorder-and-postorder-traversal'
primary_tags:
  - '[[binary-tree]]'
  - '[[divide-and-conquer]]'
subtle_tags:
  - '[[flatten_tree_to_sequence]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0098-validate-binary-search-tree/NOTES|0098-validate-binary-search-tree]]'
  - '[[leetcode/0105-construct-binary-tree-from-preorder-and-inorder-traversal/NOTES|0105-construct-binary-tree-from-preorder-and-inorder-traversal]]'
  - '[[leetcode/0230-kth-smallest-element-in-a-bst/NOTES|0230-kth-smallest-element-in-a-bst]]'
---

## Explanations

No stronger latent-friction inference is supported beyond the current comments and prior notes.

### Subtle Tags
- [[flatten_tree_to_sequence]]: leveraging that a specific traversal order of a tree maps to a well-understood sequence property (inorder BST = sorted array)

### Related Reasoning
- [[leetcode/0098-validate-binary-search-tree/NOTES|0098-validate-binary-search-tree]]: both show [[flatten_tree_to_sequence]]
- [[leetcode/0105-construct-binary-tree-from-preorder-and-inorder-traversal/NOTES|0105-construct-binary-tree-from-preorder-and-inorder-traversal]]: both show [[flatten_tree_to_sequence]]
- [[leetcode/0230-kth-smallest-element-in-a-bst/NOTES|0230-kth-smallest-element-in-a-bst]]: both show [[flatten_tree_to_sequence]]

### Signals
- Comment: `identical mirror image of` the preorder problem -- recognized the structural symmetry
