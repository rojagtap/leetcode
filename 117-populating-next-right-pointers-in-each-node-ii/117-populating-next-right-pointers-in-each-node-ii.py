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
    def connect(self, root: 'Node') -> 'Node':
        head = ptr = root
        while ptr:
            prev = None
            while head:
                if head.left:
                    if prev:
                        prev.next = head.left
                    prev = head.left
                
                if head.right:
                    if prev:
                        prev.next = head.right
                    prev = head.right
                
                head = head.next
            
            while ptr:
                if ptr.left:
                    head = ptr.left
                    break
                if ptr.right:
                    head = ptr.right
                    break
                
                ptr = ptr.next
            
            if head:
                ptr = head
                
        return root