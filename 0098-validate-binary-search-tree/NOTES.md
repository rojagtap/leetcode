---
problem_id: '0098'
platform: 'leetcode'
title: 'Validate Binary Search Tree'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0098-validate-binary-search-tree'
primary_tags:
  - '[[binary-tree]]'
  - '[[bst]]'
subtle_tags:
  - '[[flatten_tree_to_sequence]]'
candidate_tags: []
mistakes: []
related:
  - '[[leetcode/0105-construct-binary-tree-from-preorder-and-inorder-traversal/NOTES|0105-construct-binary-tree-from-preorder-and-inorder-traversal]]'
  - '[[leetcode/0106-construct-binary-tree-from-inorder-and-postorder-traversal/NOTES|0106-construct-binary-tree-from-inorder-and-postorder-traversal]]'
  - '[[leetcode/0230-kth-smallest-element-in-a-bst/NOTES|0230-kth-smallest-element-in-a-bst]]'
---

## Explanations

The solver recognized that an inorder traversal of a valid BST produces a strictly increasing sequence, reducing BST validation to a sorted-array check. The use of `LONG_MIN` as sentinel for the previous value handles the edge case where node values can be `INT_MIN`. Clean implementation with no wrong paths.

### Subtle Tags
- [[flatten_tree_to_sequence]]: leveraging that a specific traversal order of a tree maps to a well-understood sequence property (`inorder BST = sorted array`)

### Related Reasoning
- [[leetcode/0105-construct-binary-tree-from-preorder-and-inorder-traversal/NOTES|0105-construct-binary-tree-from-preorder-and-inorder-traversal]]: both show [[flatten_tree_to_sequence]]
- [[leetcode/0106-construct-binary-tree-from-inorder-and-postorder-traversal/NOTES|0106-construct-binary-tree-from-inorder-and-postorder-traversal]]: both show [[flatten_tree_to_sequence]]
- [[leetcode/0230-kth-smallest-element-in-a-bst/NOTES|0230-kth-smallest-element-in-a-bst]]: both show [[flatten_tree_to_sequence]]

### Signals
- `flat bst in inorder is a sorted array (since binary search is done on a sorted array)`
- `each prev element < next in a sorted array`
- `traverse in inorder and see if at any point next < prev if yes then false`
