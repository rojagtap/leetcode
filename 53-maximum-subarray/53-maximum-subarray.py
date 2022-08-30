import math

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum = -math.inf
        runningsum = 0
        
        for i in range(len(nums)):
            runningsum = max(nums[i], runningsum + nums[i])
            maxsum = max(maxsum, runningsum)
            
        return maxsum