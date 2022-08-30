class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        freq = {0: 0, 1: 0}
        longest = 0
        
        l = 0
        for r in range(len(nums)):
            freq[nums[r]] += 1
            
            if freq[0] > 1:
                freq[nums[l]] -= 1
                l += 1
                
            longest = max(longest, r - l)
            
        return longest