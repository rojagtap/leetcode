class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        current = strs.pop(0)
        prefix = current
        
        for s in strs:
            prefix = ""
            
            i = 0
            while i < len(s) and i < len(current) and current[i] == s[i]:
                prefix += s[i]
                i += 1
            
            current = prefix
            
        return prefix