import math
from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        largests = []
        if not root:
            return largests
        
        queue = deque([root])
        while queue:
            level_max = -math.inf
            level_size = len(queue)
            
            for _ in range(level_size):
                node = queue.popleft()
                level_max = max(level_max, node.val)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                                    
            largests.append(level_max)
            
        return largests