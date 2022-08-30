import math

class Solution:
    # O(n2), O(1), slow-fast pointers
    def circularArrayLoop(self, arr: List[int]) -> bool:        
        for start in range(len(arr)):
            slow, fast = start, start
            sign = math.copysign(1, arr[start])
            
            while True:
                fast = (fast + arr[fast]) % len(arr)
                
                if sign != math.copysign(1, arr[fast]):
                    break

                if fast == (fast + arr[fast]) % len(arr):
                    break
                
                slow = (slow + arr[slow]) % len(arr)
                fast = (fast + arr[fast]) % len(arr)
                
                if sign != math.copysign(1, arr[fast]):
                    break
                
                if slow == fast:
                    return True
                                
        return False

    # O(n2), O(n), hash
#     def circularArrayLoop(self, arr: List[int]) -> bool:
#         for start in range(len(arr)):
#             ptr = start
#             visited = set()
#             sign = math.copysign(1, arr[start])
#             while True:
#                 visited.add(ptr)
                
#                 if ptr == (ptr + arr[ptr]) % len(arr):
#                     break
                    
#                 ptr = (ptr + arr[ptr]) % len(arr)
                
#                 if sign != math.copysign(1, arr[ptr]):
#                     break
                    
#                 if ptr in visited:
#                     return True
                
#         return False