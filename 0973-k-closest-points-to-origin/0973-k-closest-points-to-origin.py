class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.dist = x * x + y * y
        
    def __lt__(self, other):
        return self.dist > other.dist


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        closest = []
        for x, y in points:
            heappush(closest, Point(x, y))
            
            if len(closest) > k:
                heappop(closest)
                
        return [(c.x, c.y) for c in closest]