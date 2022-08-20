class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if self.is_palindrome(word):
                return word
        else:
            return ""
        
    def is_palindrome(self, s: str) -> bool:
        length = len(s)
        for i in range((length // 2) + 1):
            if s[i] != s[length - i - 1]:
                return False
        
        return True