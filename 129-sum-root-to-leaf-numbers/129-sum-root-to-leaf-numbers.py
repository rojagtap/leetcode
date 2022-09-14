# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
#    O(n), O(1), morris traversal
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        total = currsum = 0
        
        while root:
            if not root.left:
                currsum = currsum * 10 + root.val
                
                if not root.right:
                    total += currsum
                
                root = root.right
            else:
                steps = 1
                node = root.left
                while node.right and node.right != root:
                    steps += 1
                    node = node.right
                
                if not node.right:
                    node.right = root
                    currsum = currsum * 10 + root.val
                    root = root.left
                else:
                    node.right = None
                    root = root.right
                    
                    if not node.left:
                        total += currsum
                        
                    while steps:
                        currsum //= 10
                        steps -= 1
                        
        return total         
    
    
#    O(n), O(h), dfs stack
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
            
    
#     O(n), O(h), dfs recursive
#     def sumNumbers(self, root: Optional[TreeNode]) -> int:
        
#         def addition(node, currsum):
#             nonlocal total
#             currsum += node.val
#             if not node.left and not node.right:
#                 total += currsum
#             else:
#                 currsum *= 10
#                 if node.left:
#                     addition(node.left, currsum)

#                 if node.right:
#                     addition(node.right, currsum)
                
#         total = 0
#         addition(root, 0)
        
#         return total