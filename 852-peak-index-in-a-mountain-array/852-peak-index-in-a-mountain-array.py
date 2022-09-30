class Solution:
    # O(logn), O(1), binary search
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l, r = 0, len(arr) - 1
        
        while l <= r:
            mid = (l + r) // 2
            
            if arr[mid - 1] < arr[mid] > arr[mid + 1]:
                return mid
            elif arr[mid - 1] < arr[mid]:
                l = mid + 1
            elif arr[mid] > arr[mid + 1]:
                r = mid