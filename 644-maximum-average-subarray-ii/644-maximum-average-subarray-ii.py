import math

class Solution:
    '''
    average of any subarray cannot exceed the max and cannot be smaller than the min of the whole array
    so we pick a number (curr) between the smallest and the largest.
    Now if there exist a subarray (of length m) whose average > curr
    Thus,
    
    (nums[i], nums[i + 1], nums[i + 2] + ... + nums[i + m]) / m >= curr
    (nums[i], nums[i + 1], nums[i + 2] + ... + nums[i + m]) >= curr * m
    
    (nums[i], nums[i + 1], nums[i + 2] + ... + nums[i + m]) - curr * m >= 0
    '''
    
    # O(nlogn) binary search
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        smallest, largest = math.inf, -math.inf
        
        for num in nums:
            smallest = min(smallest, num)
            largest = max(largest, num)
            
        prev, curr = smallest, largest
        while abs(prev - curr) > 1e-5:
            prev = curr
            curr = (largest + smallest) / 2
            
            if self.can_exceed(nums, curr, k):
                smallest = curr
            else:
                largest = curr
                
        return curr
    
    def can_exceed(self, nums, curr, k):
        currsum = sum(nums[:k]) - (k * curr)
        
        if currsum >= 0:
            return True
        
        leftsum, minsum = 0, 0
        for i in range(k, len(nums)):
            currsum += (nums[i] - curr)
            leftsum += (nums[i - k] - curr)
            
            minsum = min(minsum, leftsum)
            
            if currsum - minsum >= 0:
                return True
            
        return False
        
    
#     O(n2), O(1), prefix sum and sliding window
#     def findMaxAverage(self, nums: List[int], k: int) -> float:
#         prefixsum = sum(nums[:k])
#         maxavg = prefixsum / k
#         for i in range(k, len(nums)):
#             prefixsum += nums[i]
#             currsum = prefixsum
            
#             j = 0
#             while (i - j + 1) >= k:
#                 avg = currsum / (i - j + 1)
#                 currsum -= nums[j]
#                 maxavg = max(maxavg, avg)
#                 j += 1
        
#         return maxavg
            