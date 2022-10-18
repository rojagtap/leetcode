class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        @cache
        def permutate(end, currsum):            
            if end == -1:
                return int(currsum == target)
            
            count = 0
            count += permutate(end - 1, currsum + nums[end])
            count += permutate(end - 1, currsum - nums[end])
            
            return count
        
        return permutate(len(nums) - 1, 0)