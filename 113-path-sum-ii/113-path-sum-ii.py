# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        all_paths = []
        if not root:
            return all_paths
        
        self.recurse(root, targetSum, [], all_paths)
        return all_paths
    
        
    def recurse(self, node, target, path, all_paths):
        path.append(node.val)
        if not node.left and not node.right and target == node.val:
            all_paths.append(path[:])
        
        if node.left:
            self.recurse(node.left, target - node.val, path, all_paths)
        if node.right:
            self.recurse(node.right, target - node.val, path, all_paths)
            
        del path[-1]
        