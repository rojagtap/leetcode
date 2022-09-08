# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    '''
    create a circular linked list and move head to (length - k)th item
    '''
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head:
            return head
        
        ptr = head
        length = 1
        
        while ptr.next:
            ptr = ptr.next
            length += 1
            
        ptr.next = head
        jumps = (length - k) % length
        
        while jumps:
            ptr = ptr.next
            jumps -= 1
            
        head = ptr.next
        ptr.next = None
        
        return head