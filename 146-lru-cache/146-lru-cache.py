# O(1), O(capacity), Doubly-Linked List
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None

            
class LRUCache:
    def __init__(self, capacity: int):
        self.head = None
        self.tail = None
        
        self.capacity = capacity
        self.cache = dict()
        
    def _add(self, node):
        node.next = self.head
        node.prev = None
        
        if self.head:
            self.head.prev = node
        
        self.head = node
        
        if not self.tail:
            self.tail = node
        
    def _used(self, node):
        self._pop(node)
        self._add(node)
        
    def _pop(self, node=None):
        if not node:
            node = self.tail
        
        if node.prev:
            node.prev.next = node.next
        else:
            self.head = node.next
            
        if node.next:
            node.next.prev = node.prev
        else:
            self.tail = node.prev
        
        node.next = node.prev = None
        return node
            
    def get(self, key: int) -> int:
        if key in self.cache:
            self._used(self.cache[key])
            return self.cache[key].value
        else:
            return -1
        
    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache[key].value = value
            self._used(self.cache[key])
        else:
            if len(self.cache) == self.capacity:
                self.cache.pop(self._pop().key)
                
            self.cache[key] = Node(key, value)
            self._add(self.cache[key])

        
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)