# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ptrs = []
    
    def isSubtree(self, root: Optional[TreeNode], subroot: Optional[TreeNode]) -> bool:
        self.__find(root, subroot)
                
        for ptr in self.ptrs:
            if self.__equals(ptr, subroot):
                return True
        
        return False
    
    def __find(self, root, subroot):
        if not root:
            return
        elif root.val == subroot.val:
            self.ptrs.append(root)
        
        self.__find(root.left, subroot)
        self.__find(root.right, subroot)
        
    def __equals(self, a, b):
        if not a and not b:
            return True
        elif (a and not b) or (not a and b):
            return False
        else:
            return a.val == b.val and self.__equals(a.left, b.left) and self.__equals(a.right, b.right)
