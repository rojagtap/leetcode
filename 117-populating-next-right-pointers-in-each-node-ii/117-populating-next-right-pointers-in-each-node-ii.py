"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    # O(n), O(1), no bfs/no queue
    def connect(self, root: 'Node') -> 'Node':
        ptr = root
        while ptr:
            head = ptr
            ptr, prev = None, None
            while head:
                if head.left:
                    if prev:
                        prev.next = head.left
                    prev = head.left
                    
                    if not ptr:
                        ptr = head.left
                
                if head.right:
                    if prev:
                        prev.next = head.right
                    prev = head.right
                    
                    if not ptr:
                        ptr = head.right
                
                head = head.next
                            
        return root