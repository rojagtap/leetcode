# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if left == right:
            return head
        
        start = head
        while left > 2:
            start = start.next
            left -= 1
            
        end = head
        while right > 1:
            end = end.next
            right -= 1

            
        last = end
        end = end.next
        last.next = None
        
        if left == 1:
            first, last = self.reverse(start)
            head = first
        else:
            first, last = self.reverse(start.next)
            start.next = first
        
        last.next = end

        return head
    
    
    def reverse(self, head):
        prev, curr = None, head
        
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
            
        return prev, head