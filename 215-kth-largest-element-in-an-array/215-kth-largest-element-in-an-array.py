import random


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        kthlargest = len(nums) - k
        start, end = 0, len(nums) - 1
        
        while start <= end:
            kth = self.partition(nums, start, end)
            if kth < kthlargest:
                start = kth + 1
            elif kth > kthlargest:
                end = kth - 1
            else:
                return nums[kth]
            
        return -1
    
    
    def partition(self, arr, start, end):
        pivotidx = random.randint(start, end)
        arr[pivotidx], arr[end] = arr[end], arr[pivotidx]

        pivot = arr[end]
        left = start
        
        for right in range(start, end):
            if arr[right] <= pivot:
                arr[left], arr[right] = arr[right], arr[left]
                left += 1
                
        arr[left], arr[end] = arr[end], arr[left]
        
        return left