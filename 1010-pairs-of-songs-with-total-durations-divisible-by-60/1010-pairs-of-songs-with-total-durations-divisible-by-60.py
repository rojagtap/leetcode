class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        freq = dict()
        
        count = 0
        for duration in time:
            count += freq.get((60 - duration) % 60, 0)
            freq[duration % 60] = freq.get(duration % 60, 0) + 1
            
        return count