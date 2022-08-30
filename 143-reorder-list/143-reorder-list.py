# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        mid = self.get_mid(head)
        second = mid.next
        mid.next = None
        
        rev = self.reverse(second)
        while rev:
            next = rev.next
            rev.next = head.next
            head.next = rev
            rev = next
            head = head.next.next
        

    def get_mid(self, head):
        slow = fast = head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        return slow
        
        
    def reverse(self, head):
        curr = head
        prev = None
        
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        
        return prev