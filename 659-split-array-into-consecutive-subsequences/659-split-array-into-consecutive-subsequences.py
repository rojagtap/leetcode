class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        freq = dict()
        subseq = dict()
        
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
            
        for num in nums:
            if freq.get(num, 0) == 0:
                continue
                
            if subseq.get(num - 1, 0) > 0:
                subseq[num] = subseq.get(num, 0) + 1
                subseq[num - 1] -= 1
                freq[num] -= 1
            elif freq.get(num + 1, 0) > 0 and freq.get(num + 2, 0) > 0:
                subseq[num + 2] = subseq.get(num + 2, 0) + 1
                freq[num] -= 1
                freq[num + 1] -= 1
                freq[num + 2] -= 1
            else:
                return False
            
        return True