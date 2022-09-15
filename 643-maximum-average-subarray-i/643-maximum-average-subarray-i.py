import math

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        maxavg = -math.inf
        
        left = 0
        currsum = 0
        for right in range(len(nums)):
            currsum += nums[right]
            
            if right >= k - 1:
                maxavg = max(maxavg, currsum / k)
                currsum -= nums[left]
                left += 1
                
        return maxavg