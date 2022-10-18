# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # O(n2n), O(n)
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        @cache
        def permutate(start, end):
            if start >= end:
                return [None]
            
            roots = []
            for i in range(start, end):
                left_trees = permutate(start, i)
                right_trees = permutate(i + 1, end)
                
                for ltree in left_trees:
                    for rtree in right_trees:
                        roots.append(TreeNode(i, ltree, rtree))
                        
            return roots
        
        return permutate(1, n + 1)
