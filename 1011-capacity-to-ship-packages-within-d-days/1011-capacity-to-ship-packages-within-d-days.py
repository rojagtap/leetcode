class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        low, high = max(weights), sum(weights)
        
        while low < high:
            mid = (low + high) // 2
            
            currdays = 0
            currweight = 0
            for weight in weights:
                currweight += weight
                if currweight > mid:
                    currdays += 1
                    currweight = weight
            
            currdays += 1
            if currdays > days:
                low = mid + 1
            else:
                high = mid
            
        return low