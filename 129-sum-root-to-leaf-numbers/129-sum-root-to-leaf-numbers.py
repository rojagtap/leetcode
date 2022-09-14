# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
#     # O(n), O(h), dfs stack
#     def sumNumbers(self, root: Optional[TreeNode]) -> int:
#         total = 0
#         stack = [(root, 0)]
#         while stack:
#             node, currsum = stack.pop()
#             currsum += node.val
            
#             if not node.left and not node.right:
#                 total += currsum
#             else:
#                 currsum *= 10
#                 if node.left:
#                     stack.append((node.left, currsum))
#                 if node.right:
#                     stack.append((node.right, currsum))
                    
#         return total
            
    
    # O(n), O(h), dfs recursive
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        
        def addition(node, currsum):
            nonlocal total
            currsum += node.val
            if not node.left and not node.right:
                total += currsum
            else:
                currsum *= 10
                if node.left:
                    addition(node.left, currsum)

                if node.right:
                    addition(node.right, currsum)
                
        total = 0
        addition(root, 0)
        
        return total