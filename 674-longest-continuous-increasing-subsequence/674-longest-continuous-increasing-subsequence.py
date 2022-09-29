class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        longest = 1
        
        l = 0
        for r in range(1, len(nums)):
            if nums[r - 1] >= nums[r]:
                l = r
            else:
                longest = max(longest, r - l + 1)
        
        return longest