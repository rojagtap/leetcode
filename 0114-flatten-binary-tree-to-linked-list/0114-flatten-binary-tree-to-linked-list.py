# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # O(n), O(n), dfs
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        
        if root:
            if root.left or root.right:
                rightmost = self.flatten(root.right)
                leftmost = self.flatten(root.left)

                if leftmost:
                    leftmost.right = root.right
                    root.right = root.left
                    root.left = None

            
                return rightmost or leftmost
            else:
                return root
        else:
            return None
