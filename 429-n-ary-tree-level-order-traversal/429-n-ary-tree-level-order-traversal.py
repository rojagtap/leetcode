"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        traversal = []
        if not root:
            return traversal
        
        queue = deque([root])
        while queue:
            level = []
            for _ in range(len(queue)):
                rear = queue.popleft()
                level.append(rear.val)

                if rear.children:
                    for child in rear.children:
                        if child:
                            queue.append(child)
                
            traversal.append(level)
        
        return traversal