"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        traversal = []
        
        if not root:
            return traversal
        
        stack = [root]
        while stack:
            top = stack.pop()
            traversal.append(top.val)
            
            if top.children:
                for i in range(len(top.children) - 1, -1, -1):
                    if top.children[i]:
                        stack.append(top.children[i])
                    
        return traversal