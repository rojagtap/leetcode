from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        traversal = []
        
        if not root:
            return traversal
        
        reverse = False
        queue = deque([root])
        while queue:
            level_size = len(queue)
            current_level = deque()
            
            while level_size:
                node = queue.popleft()
                
                if reverse:
                    current_level.appendleft(node.val)
                else:
                    current_level.append(node.val)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                    
                level_size -= 1
                
            traversal.append(list(current_level))
            reverse = not reverse
            
        return traversal
