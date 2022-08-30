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
        
        second = self.reverse(second)
        while second:
            next = second.next
            second.next = head.next
            head.next = second
            second = next
            head = head.next.next
        

    def get_mid(self, fast):
        slow = fast
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        return slow
        
        
    def reverse(self, curr):
        prev = None
        
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        
        return prev