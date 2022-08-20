class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        length = len(arr)
        
        if length < 3:
            return False
        
        sign = 1
        for i in range(1, length):
            if arr[i] - arr[i - 1] == 0:
                return False
            elif arr[i] - arr[i - 1] < 0:
                if i == 1:
                    return False
                sign = -1
            elif sign == -1:
                    return False
                
        return sign == -1