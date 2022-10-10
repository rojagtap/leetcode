# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # O(logn), O(1)
    def closestValue(self, root: Optional[TreeNode], val: float) -> int:
        diff = inf
        while root:
            if val < root.val:
                if root.val - val < abs(diff):
                    diff = val - root.val
                
                root = root.left
            elif val > root.val:
                if val - root.val < abs(diff):
                    diff = val - root.val
                    
                root = root.right
            else:
                return root.val
            
        return int(val - diff)