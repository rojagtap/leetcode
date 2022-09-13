# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        
        diff = targetSum - root.val
        
        if not root.left and not root.right:
            # leaf node
            return diff == 0
        
        return self.hasPathSum(root.left, diff) or self.hasPathSum(root.right, diff)