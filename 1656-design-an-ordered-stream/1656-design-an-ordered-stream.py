class OrderedStream:

    def __init__(self, n: int):
        self.n = n
        self.stream = [None] * self.n
        self.ptr = 0
        

    def insert(self, idKey: int, value: str) -> List[str]:
        self.stream[idKey - 1] = value
        if (idKey - 1) == self.ptr:
            start = self.ptr
            while self.ptr < self.n and self.stream[self.ptr]:
                self.ptr += 1
            else:
                if self.ptr == (self.n - 1) and self.stream[self.ptr]:
                    self.ptr += 1
            
            return self.stream[start: self.ptr]
        else:
            return []


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)