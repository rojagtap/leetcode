import heapq

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda interval: interval[0])
        
        rooms = 1
        meetings = []
        heapq.heappush(meetings, intervals[0][1])
        for i in range(1, len(intervals)):            
            if meetings[0] > intervals[i][0]:
                rooms += 1
            else:
                heapq.heappop(meetings)
            
            heapq.heappush(meetings, intervals[i][1])
            
            
        return rooms
    