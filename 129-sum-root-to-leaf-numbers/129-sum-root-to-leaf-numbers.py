# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        
        def addition(node, currsum):
            nonlocal total
            currsum += node.val
            if not node.left and not node.right:
                total += currsum
                
            currsum *= 10
            if node.left:
                addition(node.left, currsum)
                
            if node.right:
                addition(node.right, currsum)
                
        total = 0
        addition(root, 0)
        
        return total