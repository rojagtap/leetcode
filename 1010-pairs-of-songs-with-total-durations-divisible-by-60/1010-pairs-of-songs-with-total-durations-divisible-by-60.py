class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        freq = dict()
        
        count = 0
        for duration in time:
            diff = (60 - duration) % 60
            if diff in freq:
                count += freq[diff]
                
            duration %= 60
            freq[duration] = freq.get(duration, 0) + 1
            
        return count