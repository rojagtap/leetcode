# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        
        curr, next, prev = head, head.next, None
        while next:
            curr.next = next.next
            next.next = curr
            
            if head == curr:
                head = next
            
            if prev:
                prev.next = next
            prev = curr
            curr = curr.next
            next = curr.next if curr else None
            
        return head
        