class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        length = len(arr)
        
        if length < 3:
            return False
        
        # sign = 1
        # for i in range(1, length):
        #     if arr[i] - arr[i - 1] == 0:
        #         return False
        #     elif arr[i] - arr[i - 1] < 0:
        #         if i == 1:
        #             return False
        #         sign = -1
        #     elif sign == -1:
        #             return False
        
        i = 0
        
        while i < (length - 1) and arr[i] < arr[i + 1]:
            i += 1
            
        if i == 0 or i == (length - 1):
            return False
        
        while i < (length - 1) and arr[i] > arr[i + 1]:
            i += 1
                
        return i == (length - 1)