import math

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        l = 0
        while l < len(nums) - 1 and nums[l] <= nums[l + 1]:
            l += 1
        
        if l == len(nums) - 1:
            return 0
        
        r = len(nums) - 1
        while r > 0 and nums[r] >= nums[r - 1]:
            r -= 1
            
        submin = math.inf
        submax = -math.inf
        for i in range(l, r + 1):
            submin = min(submin, nums[i])
            submax = max(submax, nums[i])
            
        while l > 0 and nums[l - 1] > submin:
            l -= 1
            
        while r < len(nums) - 1 and nums[r + 1] < submax:
            r += 1
            
        return r - l + 1