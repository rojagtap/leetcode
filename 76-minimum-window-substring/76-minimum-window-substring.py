import math
import collections


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        freq = collections.Counter(t)
        minlen = math.inf
        
        start, end = 0, len(s)
        matches = 0
        left = 0
        for right in range(len(s)):
            if s[right] in freq:
                freq[s[right]] -= 1
                if freq[s[right]] == 0:
                    matches += 1
                    
            if matches == len(freq):
                while left < right:
                    if s[left] in freq:
                        if freq[s[left]] == 0:
                            break
                            
                        freq[s[left]] += 1
                        
                    left += 1
                    
                if (right - left + 1) < minlen:
                    start, end = left, right
                    minlen = right - left + 1
                
        if minlen != math.inf:
            return s[start: end + 1]
        else:
            return ""
        