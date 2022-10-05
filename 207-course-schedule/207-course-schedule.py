class Solution:
    # O(V + E), O(V + E) where V are vertices(courses), E are the edges (prerequisites)
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if numCourses <= 0:
            return False
        
        indegrees = {i: 0 for i in range(numCourses)}
        adjacency = defaultdict(list)
        
        for post, pre in prerequisites:
            indegrees[post] += 1
            adjacency[pre].append(post)
            
        can_take = 0
        sources = deque([course for course, pres in indegrees.items() if pres == 0])
        while sources:
            can_take += 1
            course = sources.popleft()
            
            for next_course in adjacency[course]:
                indegrees[next_course] -= 1
                if indegrees[next_course] == 0:
                    sources.append(next_course)
                    
        return can_take == numCourses
            