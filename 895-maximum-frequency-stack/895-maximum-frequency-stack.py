class FreqStack:

    def __init__(self):
        self.freq = dict()
        self.heap = []
        self.order = 0

    def push(self, val: int) -> None:
        self.order += 1
        self.freq[val] = self.freq.get(val, 0) + 1
        
        heappush(self.heap, [-self.freq[val], -self.order, val])

    def pop(self) -> int:
        top = heappop(self.heap)
        
        self.freq[top[2]] -= 1
        if not self.freq[top[2]]:
            self.freq.pop(top[2])
            
        return top[2]


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()