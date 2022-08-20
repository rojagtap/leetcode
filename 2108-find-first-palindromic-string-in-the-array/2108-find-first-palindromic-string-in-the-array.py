class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if self.isPalindrome(word):
                return word
            
        return ""
        
    def isPalindrome(self, s: str) -> bool:
        length = len(s)
        for i in range((length // 2) + 1):
            if s[i] != s[length - i - 1]:
                return False
        
        return True