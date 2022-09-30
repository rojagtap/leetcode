DELETED = -1

class MyHashSet:

    def __init__(self):
        self.size = 10 ** 5
        self.nums = [None] * self.size

    def add(self, key: int) -> None:
        idx = i = 0
        while True:
            idx = (self.__hash1(key) + i * self.__hash2(key)) % self.size
            i += 1
            if self.nums[idx] is None or self.nums[idx] == DELETED or self.nums[idx] == key:
                self.nums[idx] = key
                break
                                
    def __find(self, key):
        idx = i = 0
        while True:
            idx = (self.__hash1(key) + i * self.__hash2(key)) % self.size
            i += 1
            
            if idx >= self.size or self.nums[idx] is None or self.nums[idx] == key:
                break
            
        return idx if self.nums[idx] == key else None

    def remove(self, key: int) -> None:
        idx = self.__find(key)
        if idx is not None:
            self.nums[idx] = DELETED

    def contains(self, key: int) -> bool:
        return self.__find(key) is not None
    
    def __hash1(self, val):
        return val % self.size
    
    def __hash2(self, val):
        return (1 + val * 3) % self.size


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)