class Solution:
    # O(n), O(1) as space can be max 26
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        mapping = dict()
        tset = set()
        for i in range(len(s)):
            if (s[i] in mapping and t[i] != mapping[s[i]]) or (s[i] not in mapping and t[i] in tset):
                return False
                
            mapping[s[i]] = t[i]
            tset.add(t[i])
            
        return True
        
        