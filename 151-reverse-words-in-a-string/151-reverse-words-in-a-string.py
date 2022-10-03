class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        
        split = s.split()
        
        return " ".join(split[::-1])