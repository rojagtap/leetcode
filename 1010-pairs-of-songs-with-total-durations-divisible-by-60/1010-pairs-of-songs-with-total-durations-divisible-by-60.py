class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        freq = dict()
        
        count = 0
        for duration in time:
            diff = (60 - duration) % 60
            if diff in freq:
                count += freq[diff]
                
            freq[duration % 60] = freq.get(duration % 60, 0) + 1
            
        return count