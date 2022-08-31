class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
        intervals.sort(key=lambda x: x[0])
        
        start, end = intervals[0]
        for i in range(1, len(intervals)):
            interval = intervals[i]
            
            if self.overlap(end, interval[0]):
                end = self.coalesce(end, interval[1])
            else:
                merged.append([start, end])
                start, end = interval
        
        merged.append([start, end])
        return merged
    
    
    def overlap(self, y1, x2):
        return x2 <= y1
    
    
    def coalesce(self, y1, y2):
        return max(y1, y2)
