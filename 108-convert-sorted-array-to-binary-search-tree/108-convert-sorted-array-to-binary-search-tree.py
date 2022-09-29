# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # O(n), O(logn), preorder
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def construct(start, end):
            if start > end:
                return None
            else:
                median = (start + end + 1) // 2
                return TreeNode(nums[median], construct(start, median - 1), construct(median + 1, end))
            
        return construct(0, len(nums) - 1)
    