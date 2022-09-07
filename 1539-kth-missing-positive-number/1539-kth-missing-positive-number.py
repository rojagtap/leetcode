class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        if k <= arr[0] - 1:
            return k
        
        missing = arr[0] - 1
        for i in range(1, len(arr)):
            if arr[i] != i + 1:
                missing += (arr[i] - arr[i - 1] - 1)
                if missing >= k:
                    return arr[i] - (missing - k) - 1
                
        
        return arr[-1] - (missing - k)