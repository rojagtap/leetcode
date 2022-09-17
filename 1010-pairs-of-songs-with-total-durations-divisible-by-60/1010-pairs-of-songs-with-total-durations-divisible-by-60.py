class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        freq = dict()
        
        count = 0
        for duration in time:
            if (60 - duration) % 60 in freq:
                count += freq[(60 - duration) % 60]
                
            freq[duration % 60] = freq.get(duration % 60, 0) + 1
            
        return count