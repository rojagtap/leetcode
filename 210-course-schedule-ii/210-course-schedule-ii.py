class Solution:
    # Topological sorting
    # O(V + E), O(V + E) where V is # of vertices (courses), E is the # of edges (prerequisites)
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        order = []
        if numCourses <= 0:
            return order
        
        indegrees = {i: 0 for i in range(numCourses)}
        adjacency = defaultdict(list)
        
        for post, pre in prerequisites:
            indegrees[post] += 1
            adjacency[pre].append(post)
            
        sources = deque([course for course, pres in indegrees.items() if pres == 0])
        while sources:
            course = sources.popleft()
            order.append(course)
            
            for next_course in adjacency[course]:
                indegrees[next_course] -= 1
                if indegrees[next_course] == 0:
                    sources.append(next_course)
                    
        return order if len(order) == numCourses else []
