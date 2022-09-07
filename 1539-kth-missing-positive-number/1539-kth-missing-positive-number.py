class Solution:
    '''
    Since the numbers are positive integers sorted in a strictly increasing order, we can conclude that i + 1 is the ideal position for any number arr[i]
    So if a number is not at its ideal place, it means that it is misplaced by arr[i] - (i + 1), i.e., arr[i] - (i + 1) numbers are missing so far
    We can use binary search to look for the HIGHEST NUMBER WHICH HAS LESS MISSING NUMBERS THAN k. For example if arr is [2,3,4,7,11] and k is 2, then there is 1 missing number until 4 and 3 missing numbers at 7 so we take 4.
    Once we have that, we can simply add the difference between k and the missing elements so far (i.e., the remaining ones) to 4 and return
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