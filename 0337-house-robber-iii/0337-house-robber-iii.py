# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    @lru_cache(maxsize=None)
    def rob(self, node: Optional[TreeNode]) -> int:
        if not node:
            return 0

        maxmoney = node.val
        maxmoney += self.rob(node.left.left) + self.rob(node.left.right) if node.left else 0
        maxmoney += self.rob(node.right.left) + self.rob(node.right.right) if node.right else 0

        return max(maxmoney, self.rob(node.left) + self.rob(node.right))
        
