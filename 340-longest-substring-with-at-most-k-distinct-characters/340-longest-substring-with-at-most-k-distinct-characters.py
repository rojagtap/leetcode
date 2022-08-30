import math

class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        freq = dict()
        distinct = 0
        maxsub = -math.inf
        
        l = 0
        for r in range(len(s)):
            if s[r] not in freq or freq[s[r]] == 0:
                freq[s[r]] = 0
                distinct += 1
                
            freq[s[r]] += 1
            
            while distinct > k:
                freq[s[l]] -= 1
                if freq[s[l]] == 0:
                    distinct -= 1
                    
                l += 1

            maxsub = max(maxsub, r - l + 1)
                    
        return maxsub
        
        