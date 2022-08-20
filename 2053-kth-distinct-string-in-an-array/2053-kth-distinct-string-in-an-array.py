class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        freq = dict()
        
        for a in arr:
            freq[a] = freq.get(a, 0) + 1
            
        for a in arr:
            if freq[a] == 1:
                k -= 1
                
                if k == 0:
                    return a
        
        return ""