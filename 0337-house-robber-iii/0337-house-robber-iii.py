# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # O(n), O(n), backtracking + memoization
    def rob(self, root: Optional[TreeNode]) -> int:
        @lru_cache(maxsize=None)
        def pick(node):
            if not node:
                return 0
            
            maxmoney = node.val
            maxmoney += pick(node.left.left) + pick(node.left.right) if node.left else 0
            maxmoney += pick(node.right.left) + pick(node.right.right) if node.right else 0
            
            return max(maxmoney, pick(node.left) + pick(node.right))
        
        return pick(root)