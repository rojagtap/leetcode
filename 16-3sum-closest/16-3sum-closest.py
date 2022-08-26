import math

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        length = len(nums)
        diff = math.inf
        nums.sort()
        
        for i in range(length - 2):
            l = i + 1
            r = length - 1
            while l < r:
                currsum = nums[i] + nums[l] + nums[r]
                
                if abs(target - currsum) < abs(diff):
                    diff = target - currsum
                elif currsum == target:
                    return target
                    
                if currsum < target:
                    l += 1
                else:
                    r -= 1
                    
        return target - diff
                
                