# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        
        prev, curr, next = head, head.next, None
        while curr:
            prev.next = curr.next
            curr.next = prev
            
            if head == prev:
                head = curr
            
            if next:
                next.next = curr
            next = prev
            prev = prev.next
            curr = prev.next if prev else None
            
        return head
        