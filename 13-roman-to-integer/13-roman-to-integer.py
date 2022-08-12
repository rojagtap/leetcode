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
        
        length = len(s)
        decimal = 0
        for i in range(length):
            sub = 0
            if i < length - 1 and rom2dec[s[i]] < rom2dec[s[i + 1]]:
                decimal -= rom2dec[s[i]]
            else:
                decimal += rom2dec[s[i]]
                
        return decimal
                