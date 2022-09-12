from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def boundaryOfBinaryTree(self, root: Optional[TreeNode]) -> List[int]:
        leftmost = [root]
        left = root.left
        while left:
            leftmost.append(left)
            left = left.left or left.right
            
                    
        leaf = []
        stack = [root]
        while stack:
            node = stack.pop()

            if node.left or node.right:
                if node.right:
                    stack.append(node.right)
                if node.left:
                    stack.append(node.left)
            else:
                leaf.append(node)
                                
        
        rightmost = [root]
        right = root.right
        while right:
            rightmost.append(right)
            right = right.right or right.left
        
        
        boundary = []
        seen = set()
        def populate(arr):
            for a in arr:
                if a not in seen:
                    boundary.append(a.val)
                    seen.add(a)
                    
        populate(leftmost)
        populate(leaf)
        populate(reversed(rightmost))
        
            
        return boundary