class Solution:
    def romanToInt(self, s: str) -> int:
        rom2dec = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        
        decimal = 0
        for i in range(len(s)):
            sub = 0
            if i < len(s) - 1 and rom2dec[s[i]] < rom2dec[s[i + 1]]:
                decimal -= rom2dec[s[i]]
            else:
                decimal += rom2dec[s[i]]
                
        return decimal
                