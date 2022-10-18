class Solution:
    # O(n), O(n), backtracking + memoization
    def canPartition(self, nums: List[int]) -> bool:
        @cache
        def partition(currsum, i):
            if currsum == total - currsum:
                return True

            if currsum > total - currsum or i == len(nums):
                return False

            return partition(currsum + nums[i], i + 1) or partition(currsum, i + 1)
    
        total = sum(nums)
        
        return False if total & 1 else partition(0, 0)