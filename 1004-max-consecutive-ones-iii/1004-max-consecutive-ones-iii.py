class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        freq = {0: 0, 1: 1}
        maxones = 0
        
        l = 0
        for r in range(len(nums)):
            freq[nums[r]] += 1
            
            while freq[0] > k:
                freq[nums[l]] -= 1
                l += 1
                
            maxones = max(maxones, r - l + 1)
            
        return maxones