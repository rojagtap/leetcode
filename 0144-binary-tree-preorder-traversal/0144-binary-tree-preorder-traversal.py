# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution: 
    # O(n), O(logn)
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def preorder(node):
            if node:
                traversal.append(node.val)
                preorder(node.left)
                preorder(node.right)

        traversal = []
        preorder(root)
        
        return traversal