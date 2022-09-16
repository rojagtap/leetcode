import math

class Solution:
    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        nums.sort()
        
        maxsum = -math.inf
        left, right = 0, len(nums) - 1
        while left < right:
            if nums[left] + nums[right] < k:
                maxsum = max(maxsum, nums[left] + nums[right])
                left += 1
            else:
                right -= 1
        
        if maxsum == -math.inf:
            return - 1
        else:
            return maxsum