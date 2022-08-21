class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        zero = ord("0")
        
        i = len(num1) - 1
        j = len(num2) - 1
        
        add = []
        carry = 0
        while i >= 0 and j >= 0:
            currsum = ord(num1[i]) + ord(num2[j]) - (2 * zero) + carry
            digit = currsum % 10
            
            add.append(str(digit))
            
            carry = currsum // 10
            
            i -= 1
            j -= 1
            
        
        while i >= 0:
            currsum = ord(num1[i]) - zero + carry
            digit = currsum % 10
            
            add.append(str(digit))
            
            carry = currsum // 10
            
            i -= 1
            
        
        while j >= 0:
            currsum = ord(num2[j]) - zero + carry
            digit = currsum % 10
            
            add.append(str(digit))
            
            carry = currsum // 10
            
            j -= 1
            
        if carry != 0:
            add.append(str(carry))
        
        return ''.join(add)[::-1]

        
#     Solution without big ints consideration
#     def addStrings(self, num1: str, num2: str) -> str:
#         zero = ord("0")
        
#         int1 = 0
#         factor = 10
#         for num in num1:
#             digit = ord(num) - zero
#             int1 = int1 * factor + digit
            
#         int2 = 0
#         factor = 10
#         for num in num2:
#             digit = ord(num) - zero
#             int2 = int2 * factor + digit
                    
#         return str(int1 + int2)