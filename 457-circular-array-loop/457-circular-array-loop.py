import math

class Solution:
    def circularArrayLoop(self, arr: List[int]) -> bool:
        for start in range(len(arr)):
            ptr = start
            visited = set()
            sign = math.copysign(1, arr[start])
            while True:
                visited.add(ptr)
                
                if ptr == (ptr + arr[ptr]) % len(arr):
                    break
                    
                ptr = (ptr + arr[ptr]) % len(arr)
                
                if sign != math.copysign(1, arr[ptr]):
                    break
                    
                if ptr in visited:
                    return True
                
        return False