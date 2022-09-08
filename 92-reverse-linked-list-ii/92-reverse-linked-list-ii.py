# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right:
            return head
        
        prev = None
        
        start = end = head
        diff = right - left
        while diff > 0:
            end = end.next
            diff -= 1
            
        while left > 1:
            prev = start
            start = start.next
            end = end.next
            left -= 1
                
        next = end.next
        
        start, end = self.reverse(start, next)
        
        if prev:
            prev.next = start
        else:
            head = start
            
        end.next = next

        return head
    
    
    def reverse(self, head, stop):
        prev, curr = None, head
        
        while curr != stop:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
            
        return prev, head