# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def construct(start, end):
            if start > end:
                return None
            elif start == end:
                return TreeNode(val=nums[start])
            else:
                median = start + (end - start + 1) // 2
                return TreeNode(val=nums[median], left=construct(start, median - 1), right=construct(median + 1, end))
            
        return construct(0, len(nums) - 1)
    