class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = dict()
        most_freq = 0
        longest = 0
        
        l = 0
        for r in range(len(s)):
            freq[s[r]] = freq.get(s[r], 0) + 1
            
            most_freq = max(most_freq, freq[s[r]])
            
            if (r - l + 1) - most_freq > k:
                if freq[s[l]] == most_freq:
                    most_freq -= 1

                freq[s[l]] -= 1
                l += 1
                
            longest = max(longest, r - l + 1)
                
        return longest