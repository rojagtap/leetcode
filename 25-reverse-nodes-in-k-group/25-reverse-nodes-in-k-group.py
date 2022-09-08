# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k == 1:
            return head
        
        prev = None
        start = end = head
        
        while end:
            diff = k - 1
            while diff:
                end = end.next
                diff -= 1
                if not end:
                    return head
        
            next = end.next
            
            start, end = self.reverse(start, next)
            
            if prev:
                prev.next = start
            else:
                head = start
                
            end.next = next
            
            prev = end
            start = end = next
            
        return head
        
    
    def reverse(self, start, stop):
        prev, curr = None, start
        
        while curr != stop:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
            
        return prev, start