# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        hash = set()
        
        while head:
            if head in hash:
                return head
            
            hash.add(head)
            head = head.next
        
        return None