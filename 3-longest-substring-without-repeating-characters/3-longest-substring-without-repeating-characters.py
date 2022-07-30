class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
#         hash = dict()
#         length = len(s)
#         longest = 1
#         l = 0
        
#         if length == 0 or length == 1:
#             return length
                    
#         for r in range(length):
#             if s[r] in hash:
#                 longest = max(longest, r - l)
#                 l = hash[s[r]] + 1
            
#             hash[s[r]] = r
        
#         return max(longest, (r + 1) - l)
        
    def lengthOfLongestSubstring(self, s: str) -> int:

        length = len(s)
        
        if length == 0 or length == 1:
            return length
        
        substring = 1
        const = "placeholder"
        
        for i in range(length - 1):
            h = {s[i]: const}
            temp = 1
            for j in range(i + 1, length):
                if not h.get(s[j], None):
                    h[s[j]] = const
                    temp += 1
                else: 
                    break
            
            if temp > substring:
                substring = temp
                
        return substring
        