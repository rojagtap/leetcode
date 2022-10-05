class Solution:
    # O(nlogn), O(n), two heaps
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        max_duration = []
        min_last_day = []
        for duration, day in courses:
            heappush(min_last_day, [day, duration])
        
        days = 0
        while min_last_day:
            earliest = heappop(min_last_day)
            
            if days + earliest[1] <= earliest[0]:
                days += earliest[1]
                heappush(max_duration, -earliest[1])
            elif max_duration and -max_duration[0] > earliest[1]:
                days += heappop(max_duration) + earliest[1]
                heappush(max_duration, -earliest[1])
                
        return len(max_duration)
            