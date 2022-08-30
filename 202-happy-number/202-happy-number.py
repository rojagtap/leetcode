class Solution:
#     O(klogn), O(1)
    def isHappy(self, n: int) -> bool:
        slow, fast = n, n
        
        while fast != 1:
            slow = self.square_sum(slow)
            fast = self.square_sum(self.square_sum(fast))
            
            if slow == fast:
                break
            
        return fast == 1
    
#    O(klogn), O(n)
#     def isHappy(self, n: int) -> bool:
#         hash = set()
        
#         while n != 1:
#             n = self.square_sum(n)
            
#             if n in hash:
#                 return False
            
#             hash.add(n)
            
#         return True
        
        
    def square_sum(self, n):
        s = 0
        while n:
            digit = n % 10
            s += digit * digit
            n //= 10
            
        return s