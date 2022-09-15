from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k == 1:
            return nums
        
        if k == len(nums):
            return [max(nums)]
        
        
        def cleanup(i):
            if queue and queue[0] == i - k:
                queue.popleft()
                
            while queue and nums[i] > nums[queue[-1]]:
                queue.pop()
        
        
        queue = deque()
        window_max = []
        maxidx = 0
        
        for i in range(k):
            cleanup(i)
            queue.append(i)
            
            if nums[i] > nums[maxidx]:
                maxidx = i
                
        window_max.append(nums[maxidx])
        for i in range(k, len(nums)):
            cleanup(i)
            queue.append(i)
            
            window_max.append(nums[queue[0]])
            
        return window_max