class Solution:
    '''
    O(n)
    Start with left and right pointers starting at 0, 0
    
    1. Move the right pointer across the string and add each character to a hash
    2. If the character encountered is present in hash (meaning there is a repeated element), then shrink the substring from the back, until the repeated element is excluded
    
    Repeat steps 1 and 2 until the right pointer reaches the end of the string
    '''
    
    def lengthOfLongestSubstring(self, s: str) -> int:
        hash = set()
        length = len(s)
        longest = 1
        l = 0
        
        if length == 0 or length == 1:
            return length
                    
        for r in range(length):
            while s[r] in hash:
                hash.remove(s[l])
                l += 1
                
            hash.add(s[r])
            longest = max(longest, (r + 1) - l)

        
        return longest
        
#     O(n2)
#     def lengthOfLongestSubstring(self, s: str) -> int:

#         length = len(s)
        
#         if length == 0 or length == 1:
#             return length
        
#         substring = 1
#         const = "placeholder"
        
#         for i in range(length - 1):
#             h = {s[i]: const}
#             temp = 1
#             for j in range(i + 1, length):
#                 if not h.get(s[j], None):
#                     h[s[j]] = const
#                     temp += 1
#                 else: 
#                     break
            
#             if temp > substring:
#                 substring = temp
                
#         return substring
        