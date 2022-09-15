import math

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def get_sum(node):
            nonlocal maxsum

            if not node:
                return 0
            
            left = max(get_sum(node.left), 0)
            right = max(get_sum(node.right), 0)
            
            nodesum = left + right + node.val
            
            maxsum = max(maxsum, nodesum)

            return max(left, right) + node.val
        
        maxsum = -math.inf
        get_sum(root)
        return maxsum
