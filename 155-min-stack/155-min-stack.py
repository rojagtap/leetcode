import heapq

class MinStack:

    def __init__(self):
        self.stack = []
        self.heap = []
        self.size = 0
        

    def push(self, val: int) -> None:
        self.stack.append(val)
        heapq.heappush(self.heap, val)
        self.size += 1

    def pop(self) -> None:
        val = self.stack.pop()
        self.size -= 1
        
        idx = self.heap.index(val)
        self.heap[idx] = self.heap[-1]
        self.heap.pop()
        
        if idx < self.size:
            heapq._siftup(self.heap, idx)
            heapq._siftdown(self.heap, 0, idx)
            

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.heap[0]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()