import math

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
    
        def traverse(node):
            nonlocal maxsum

            if not node.left and not node.right:
                return node.val

            leftsum = rightsum = -math.inf

            if node.left:
                leftsum = traverse(node.left)

            if node.right:
                rightsum = traverse(node.right)

            pathmax = max(node.val, max(node.val + leftsum, node.val + rightsum))
            maxsum = max(maxsum, max(pathmax, max(node.val + leftsum + rightsum, max(leftsum, rightsum))))

            return pathmax
        
        
        maxsum = -math.inf
        return max(traverse(root), maxsum)
