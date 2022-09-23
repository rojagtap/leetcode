# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        def get_tree(start, end):
          if start == end:
            return [None]

          result = []
          for i in range(start, end):
            left_trees = get_tree(start, i)
            right_trees = get_tree(i + 1, end)

            for left in left_trees:
              for right in right_trees:
                result.append(TreeNode(i, left, right))

          return result
        
        return get_tree(1, n + 1)
