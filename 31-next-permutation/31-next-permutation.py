class Solution:
    # O(n), O(1)
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        i = len(nums) - 1
        while i > 0 and nums[i] <= nums[i - 1]:
            i -= 1
        
        if i:
            mindiff = i
            for j in range(i, len(nums)):
                if nums[j] > nums[i - 1] and nums[j] - nums[i - 1] < nums[mindiff] - nums[i - 1]:
                    mindiff = j
                elif nums[j] - nums[i - 1] == nums[mindiff] - nums[i - 1]:
                    mindiff = max(mindiff, j)

            nums[i - 1], nums[mindiff] = nums[mindiff], nums[i - 1]
        
        nums[i:] = reversed(nums[i:])
            