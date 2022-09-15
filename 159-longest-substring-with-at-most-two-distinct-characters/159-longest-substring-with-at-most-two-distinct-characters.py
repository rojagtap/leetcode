class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        freq = dict()
        distinct = 0
        maxlen = 0
        
        left = 0
        for right in range(len(s)):
            if freq.get(s[right], 0) == 0:
                freq[s[right]] = 0
                distinct += 1
            
            freq[s[right]] += 1
            
            while distinct > 2:
                freq[s[left]] -= 1
                if freq[s[left]] == 0:
                    distinct -= 1
                    
                left += 1
            
            maxlen = max(maxlen, right - left + 1)
            
        return maxlen