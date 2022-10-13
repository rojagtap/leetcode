# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # O(n), O(n), backtracking + memoization
    def rob(self, root: Optional[TreeNode]) -> int:
        
        @cache
        def pick(node):
            if not node:
                return 0
            
            maxmoney = node.val
            
            if node.left:
                maxmoney += pick(node.left.left) + pick(node.left.right)
            if node.right:
                maxmoney += pick(node.right.left) + pick(node.right.right)
            
            return max(maxmoney, pick(node.left) + pick(node.right))
        
        return pick(root)