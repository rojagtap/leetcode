class Solution:
    
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        @cache
        def permutate(i, currsum):            
            if i == len(nums):
                return int(currsum == target)
            
            return permutate(i + 1, currsum + nums[i]) + permutate(i + 1, currsum - nums[i])
        
        return permutate(0, 0)