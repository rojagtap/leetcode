import math

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        nums.sort() 
        diff = inf
        
        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            j = i + 1
            k = n - 1
            
            while j < k:
                s = nums[i] + nums[j] + nums[k]

                if abs(s - target) < abs(diff):
                    diff = target - s
                
                m = (j + k) // 2

                if s > target:
                    if m != k and nums[m] > (target - nums[i] - nums[j]):
                        k = m
                    else:
                        k -= 1
                elif s < target:
                    if m != j and nums[m] < (target - nums[i] - nums[k]):
                        j = m
                    else:
                        j += 1
                else:
                    return target
                    
        return target - diff

#     def threeSumClosest(self, nums: List[int], target: int) -> int:
#         length = len(nums)
#         diff = math.inf
#         nums.sort()
        
#         for i in range(length - 2):
#             if i > 0 and nums[i] == nums[i - 1]:
#                 continue
            
#             l = i + 1
#             r = length - 1
#             while l < r:
#                 currsum = nums[i] + nums[l] + nums[r]
                
#                 if abs(target - currsum) < abs(diff):
#                     diff = target - currsum
#                 elif currsum == target:
#                     return target
                    
#                 if currsum < target:
#                     l += 1
#                 else:
#                     r -= 1
                    
#         return target - diff
                