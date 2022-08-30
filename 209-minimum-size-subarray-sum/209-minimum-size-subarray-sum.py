import math

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l = 0
        currsum = 0
        minlen = math.inf
        for r in range(len(nums)):
            currsum += nums[r]
                        
            while currsum >= target:
                minlen = min(minlen, r - l + 1)
                currsum -= nums[l]
                l += 1
                
        if minlen == math.inf:
            return 0
        else:
            return minlen