class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        maxlen = 0
        freq = dict()
        
        left = 0
        most_freq = s[0]
        for right in range(len(s)):
            freq[s[right]] = freq.get(s[right], 0) + 1
            
            if freq[s[right]] > freq[most_freq]:
                most_freq = s[right]
            
            if (right - left + 1) - freq[most_freq] > k:
                freq[s[left]] -= 1
                left += 1
                
            maxlen = max(maxlen, right - left + 1)
            
        return maxlen