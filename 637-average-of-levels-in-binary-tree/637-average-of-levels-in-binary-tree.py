from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        averages = []
        queue = deque([root])
        
        while queue:
            level_sum = 0
            level_size = count = len(queue)
            
            while level_size:
                node = queue.popleft()
                
                level_sum += node.val
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                    
                level_size -= 1
                
            averages.append(level_sum / count)
            
        return averages