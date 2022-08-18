class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        count = 0
        length = len(arr) // 2
        hash = dict()
        
        for a in arr:
            hash[a] = hash.get(a, 0) + 1
            
        freq = list(hash.values())
        freq.sort(reverse=True)
        
        while length > 0:
            length -= freq[count]
            count += 1
            
        return count