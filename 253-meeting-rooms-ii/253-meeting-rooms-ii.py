import heapq

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda interval: interval[0])
        
        rooms = 1
        meetings = []
        heapq.heappush(meetings, Tuple(intervals[0]))
        for i in range(1, len(intervals)):
            interval = intervals[i]
            
            if meetings[0].val[1] > interval[0]:
                rooms += 1
            else:
                heapq.heappop(meetings)
            
            heapq.heappush(meetings, Tuple(interval))
            
            
        return rooms
    

class Tuple:
    def __init__(self, val): self.val = val
    def __lt__(self, other): return self.val[1] < other.val[1]
