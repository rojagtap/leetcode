class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:        
        l = 0
        count = 0
        currprod = 1
        for r in range(len(nums)):
            currprod *= nums[r]
            
            while l <= r and currprod >= k:
                currprod /= nums[l]
                l += 1
                
            count += (r - l + 1)
                
        return count
                