# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        def get_count(node, target, pathsum, prefix):
            if not node:
                return 0
            
            pathsum += node.val
                        
            count = prefix.get(pathsum - target, 0) + (pathsum == target)
            prefix[pathsum] = prefix.get(pathsum, 0) + 1
            
            count += get_count(node.left, target, pathsum, prefix)
            count += get_count(node.right, target, pathsum, prefix)
            
            prefix[pathsum] -= 1
            
            return count
        
        return get_count(root, targetSum, 0, dict())