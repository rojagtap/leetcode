class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
        intervals.sort(key=lambda x: x[0])
        
        start, end = intervals[0]
        for i in range(1, len(intervals)):
            interval = intervals[i]
            
            if self.overlap(start, end, interval[0], interval[1]):
                start, end = self.coalesce(start, end, interval[0], interval[1])
            else:
                merged.append([start, end])
                start, end = interval
        
        merged.append([start, end])
        return merged
    
    
    def overlap(self, x1, y1, x2, y2):
        return x2 <= x1 <= y2 or x2 <= y1 <= y2 or x1 <= x2 <= y1 or x1 <= y2 <= y1
    
    
    def coalesce(self, x1, y1, x2, y2):
        return min(x1, x2), max(y1, y2)
