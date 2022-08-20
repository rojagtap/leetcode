class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if self.is_palindrome(word):
                return word
        else:
            return ""
        
    def is_palindrome(self, s: str) -> bool:
        return s == s[::-1]