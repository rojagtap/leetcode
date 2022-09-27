class Solution:
    def hIndex(self, citations: List[int]) -> int:
        if len(citations) == 1:
            return 1 if citations[0] else 0
        
        citations.sort()
        
        hindex = 0
        low, high = 0, len(citations) - 1
        while low <= high:
            mid = low + (high - low) // 2
            h = len(citations) - mid
            
            if citations[mid] < h:
                low = mid + 1
            elif citations[mid] > h:
                hindex = max(hindex, h)
                high = mid - 1
            else:
                return h
        
        return hindex