class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        if k == 1:
            return n
        
        queue = deque()
        
        rotations = k
        for i in range(1, n + 1):
            queue.append(i)
            rotations -= 1
            
            if not rotations:
                queue.pop()
                rotations = k
        
        while len(queue) > 1:
            front = queue.popleft()
            queue.append(front)
            rotations -= 1
            
            if not rotations:
                queue.pop()
                rotations = k
                
        return queue[0]