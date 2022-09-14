# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # O(n), O(nlogn)
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        all_paths = []
        if not root:
            return all_paths
        
        self.recurse(root, "", all_paths)
        return all_paths
    
    def recurse(self, node, path, all_paths):
        path += str(node.val)
        if not (node.left or node.right):
            all_paths.append(path)
            return
            
        path += "->"
        if node.left:
            self.recurse(node.left, path, all_paths)
        if node.right:
            self.recurse(node.right, path, all_paths)
            