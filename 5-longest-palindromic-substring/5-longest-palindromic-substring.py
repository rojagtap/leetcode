class Solution:
    '''
    Instead of checking if each possible substring is a palindrome O(n3), we can construct a palindrome 'around' each character and look for the longest
    
    the get function takes a left and right pointer which expands (i-- and j++) as long as s[i] == s[j] i.e., as long as we have a palindrome
    
    Finally, the no_centre palindrome considers a pair of characters as the centre i.e., for strings like "cbbd", a palindrome cannot be constructed using just one character, so we also consider such a scenario and construct a palindromic substring for s[i] as centre and also (s[i], s[i + 1]) as the centre.
    '''
    
    def get(self, s, i, j):
        while i >= 0 and j < len(s) and s[i] == s[j]:
            i -= 1
            j += 1
            
        return j - i - 1
    
    def longestPalindrome(self, s: str) -> str:
        longest = 0
        start = 0
        end = 0
        for i in range(len(s) - 1):
            centre = self.get(s, i, i)
            no_centre = self.get(s, i, i + 1)
            palindrome = max(centre, no_centre)
            if palindrome > longest:
                longest = palindrome
                start = i - (longest - 1) // 2
                end = i + longest // 2
            
        return s[start: end + 1]