# O(1), O(1), HashTable

DELETED = -1
class MyHashSet:

    def __init__(self):
        self.size = 10 ** 5
        self.nums = [None] * self.size

    # public methods
    def add(self, key: int) -> None:
        idx = i = 0
        while True:
            idx = self.__get_index(key, i)
            i += 1
            if self.nums[idx] is None or self.nums[idx] == DELETED or self.nums[idx] == key:
                self.nums[idx] = key
                break

    def remove(self, key: int) -> None:
        idx = self.__find(key)
        if idx is not None:
            self.nums[idx] = DELETED

    def contains(self, key: int) -> bool:
        return self.__find(key) is not None
    
    
    # private methods
    def __get_index(self, key, i):
        return (self.__hash1(key) + i * self.__hash2(key)) % self.size
    
    def __find(self, key):
        idx = i = 0
        while True:
            idx = self.__get_index(key, i)
            i += 1
            
            if idx >= self.size or self.nums[idx] is None or self.nums[idx] == key:
                break
            
        return idx if self.nums[idx] == key else None
    
    def __hash1(self, key):
        return key % self.size
    
    def __hash2(self, key):
        return (1 + key * 3) % self.size


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)