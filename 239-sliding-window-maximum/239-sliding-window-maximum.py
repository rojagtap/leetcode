from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k == 1:
            return nums
        
        if k == len(nums):
            return [max(nums)]
        
        
        queue = deque()
        window_max = []
                
        for i in range(len(nums)):
            if queue and queue[0] == i - k:
                queue.popleft()
                
            while queue and nums[i] > nums[queue[-1]]:
                queue.pop()
                
            queue.append(i)
            
            if i >= k - 1:
                window_max.append(nums[queue[0]])
            
        return window_max