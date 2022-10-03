# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # O(n), O(n)
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def build(bound=None):
            if not inorder or inorder[-1] == bound:
                return None
            
            node = TreeNode(preorder.pop())
            
            node.left = build(node.val)
            inorder.pop()
            node.right = build(bound)
            
            return node
        
        preorder = preorder[::-1]
        inorder = inorder[::-1]
        
        return build()