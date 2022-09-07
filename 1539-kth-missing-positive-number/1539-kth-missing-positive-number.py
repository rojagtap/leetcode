class Solution:
    '''
    
    '''
#     O(logn), O(1) binary search
    def findKthPositive(self, arr: List[int], k: int) -> int:
        if k <= arr[0] - 1:
            return k

        left, right = 0, len(arr) - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            if arr[mid] - mid - 1 < k:
                left = mid + 1
            else:
                right = mid - 1
            
        return arr[right] + (k - (arr[right] - right - 1))
        
    
#     O(n), O(1)
#     def findKthPositive(self, arr: List[int], k: int) -> int:
#         if k <= arr[0] - 1:
#             return k
        
#         missing = arr[0] - 1
#         for i in range(1, len(arr)):
#             if arr[i] != i + 1:
#                 missing += (arr[i] - arr[i - 1] - 1)
#                 if missing >= k:
#                     return arr[i] - (missing - k) - 1
                
        
#         return arr[-1] - (missing - k)