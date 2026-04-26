---
problem_id: '0048'
platform: 'leetcode'
title: 'Rotate Image'
difficulty: 'medium'
language: 'cpp'
aliases:
  - '0048-rotate-image'
primary_tags:
  - '[[matrix]]'
subtle_tags: []
candidate_tags: []
mistakes:
  - '[[micro_hesitation]]'
related:
  - '[[leetcode/0007-reverse-integer/NOTES|0007-reverse-integer]]'
  - '[[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]'
  - '[[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]'
  - '[[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]'
  - '[[leetcode/0105-construct-binary-tree-from-preorder-and-inorder-traversal/NOTES|0105-construct-binary-tree-from-preorder-and-inorder-traversal]]'
---

## Explanations

The comment `try this with a piece of paper` suggests the transpose-then-reverse decomposition was derived geometrically rather than recalled fluently. The commented-out manual reverse loop indicates a minor hesitation on implementation before simplifying with `std::reverse`.

### Mistake Notes
- [[micro_hesitation]]: commented-out manual swap loop for row reversal before switching to `std::reverse`

### Related Reasoning
- [[leetcode/0007-reverse-integer/NOTES|0007-reverse-integer]]: shared [[micro_hesitation]] pattern
- [[leetcode/0054-spiral-matrix/NOTES|0054-spiral-matrix]]: shared [[micro_hesitation]] pattern
- [[leetcode/0070-climbing-stairs/NOTES|0070-climbing-stairs]]: shared [[micro_hesitation]] pattern
- [[leetcode/0091-decode-ways/NOTES|0091-decode-ways]]: shared [[micro_hesitation]] pattern
- [[leetcode/0105-construct-binary-tree-from-preorder-and-inorder-traversal/NOTES|0105-construct-binary-tree-from-preorder-and-inorder-traversal]]: shared [[micro_hesitation]] pattern

### Signals
- `to visualize this try this with a piece of paper`
- `mirror image across principal diagonal is transpose`
- commented-out manual reverse loop replaced by `std::reverse`
