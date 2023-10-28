# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        traversal = deque()
            
        if not root:
            return traversal
        
        queue = deque([root])
        while queue:
            level_size = len(queue)
            current_level = []
            
            while level_size:
                node = queue.popleft()
                current_level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                    
                level_size -= 1
                
            traversal.appendleft(current_level)
            
        return traversal