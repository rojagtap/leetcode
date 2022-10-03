"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    # O(n), O(1)
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        mapping = {None: None}
        
        ptr = head
        while ptr:
            mapping[ptr] = Node(ptr.val)
            ptr = ptr.next
        
        ptr = head
        while ptr:
            mapping[ptr].next = mapping[ptr.next]
            mapping[ptr].random = mapping[ptr.random]
            ptr = ptr.next
            
        return mapping[head]