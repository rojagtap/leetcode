import math

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        diff = math.inf
        nums.sort()
        
        for i in range(len(nums) - 2):
            if i > 0 and nums[i - 1] == nums[i]:
                continue
                
            l = i + 1
            r = len(nums) - 1
            while l < r:
                currdiff = target - (nums[i] + nums[l] + nums[r])
                
                if currdiff == 0:
                    return target
                elif abs(currdiff) < abs(diff):
                    diff = currdiff
                    
                if currdiff > 0:
                    l += 1
                else:
                    r -= 1
                    
        return target - diff
                
                