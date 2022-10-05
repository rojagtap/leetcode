class Solution:
    # O(nlogn), O(n)
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda course: course[1])
        max_duration = []

        days = 0
        for earliest in courses:            
            if days + earliest[0] <= earliest[1]:
                days += earliest[0]
                heappush(max_duration, -earliest[0])
            elif max_duration and -max_duration[0] > earliest[0]:
                days += heappop(max_duration) + earliest[0]
                heappush(max_duration, -earliest[0])
                
        return len(max_duration)
            