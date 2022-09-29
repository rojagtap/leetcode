# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # O(min(m, n)), O(min(m, n)) log(min(m, n)) average case
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if not (root1 and root2):
            return root1 or root2
        
        root1.val += root2.val
        root1.left = self.mergeTrees(root1.left, root2.left) if root1.left and root2.left else root1.left or root2.left
        root1.right = self.mergeTrees(root1.right, root2.right) if root1.right and root2.right else root1.right or root2.right
        
        return root1