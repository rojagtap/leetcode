class Solution:
    # O(n), O(1)
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = i = len(nums) - 1
        while i > 0 and nums[i] <= nums[i - 1]:
            i -= 1
        
        if i:
            for j in range(n, i - 1, -1):
                if nums[j] > nums[i - 1]:
                    nums[i - 1], nums[j] = nums[j], nums[i - 1]
                    break
        
        nums[i:] = reversed(nums[i:])
            