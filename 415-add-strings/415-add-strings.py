class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        zero = ord("0")
        
        int1 = 0
        factor = 10
        for num in num1:
            digit = ord(num) - zero
            int1 = int1 * factor + digit
            
        int2 = 0
        factor = 10
        for num in num2:
            digit = ord(num) - zero
            int2 = int2 * factor + digit
                    
        return str(int1 + int2)