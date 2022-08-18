class Solution:
    '''
    O(nlogn)
    
    1. get array element frequencies in a hash
    2. sort frequencies in reverse order
    3. count frequencies to be removed such that the total number is >= half the arr length
    '''
    def minSetSize(self, arr: List[int]) -> int:
        count = 0
        halflen = len(arr) // 2
        hash = dict()
        
        for a in arr:
            hash[a] = hash.get(a, 0) + 1
            
        freq = list(hash.values())
        freq.sort(reverse=True)
        
        while halflen > 0:
            halflen -= freq[count]
            count += 1
            
        return count