class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()

        if not s:
            return 0
                
        if s[0] == '-':
            sign = -1
            i = 1
        elif s[0] == '+':
            sign = 1
            i = 1
        else:
            sign = 1
            i = 0
            
        valid_int = "0"
        while i < len(s) and s[i].isdigit():
            valid_int += s[i]
            i += 1
            
        
        integer = int(valid_int) * sign
        
        if integer < -(2 ** 31):
            return -(2 ** 31)
        elif integer > (2 ** 31) - 1:
            return (2 ** 31) - 1
        else:
            return integer
            
        
        
        