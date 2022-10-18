class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        @lru_cache(maxsize=None)
        def partition(currsum, i):
            if currsum == total - currsum:
                return True

            if i == len(nums):
                return False

            return partition(currsum + nums[i], i + 1) or partition(currsum, i + 1)
    
        total = sum(nums)
        if total & 1:
            return False
        
        return partition(0, 0)