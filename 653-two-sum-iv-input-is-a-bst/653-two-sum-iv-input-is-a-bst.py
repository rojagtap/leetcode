# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        flag = set()
        entryset = set()
        
        def inorder(node):
            if node:
                inorder(node.left)
                if (k - node.val) in entryset:
                    flag.add(True)
                else:
                    entryset.add(node.val)
                inorder(node.right)
                
        inorder(root)
        
        return bool(flag)