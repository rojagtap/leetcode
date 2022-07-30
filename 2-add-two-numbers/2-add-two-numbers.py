# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l = ListNode(next=ListNode())
        iterator = l
        
        carry = 0
        while l1 and l2:
            iterator = iterator.next
            add = l1.val + l2.val + carry
            iterator.val = add % 10
            carry = add // 10
            
            l1 = l1.next
            l2 = l2.next
            iterator.next = ListNode()
            
        while l1:
            iterator = iterator.next
            add = l1.val + carry
            iterator.val = add % 10
            carry = add // 10
            
            l1 = l1.next
            iterator.next = ListNode()
            
        while l2:
            iterator = iterator.next
            add = l2.val + carry
            iterator.val = add % 10
            carry = add // 10
            
            l2 = l2.next
            iterator.next = ListNode()
            
        if carry:
            iterator.next.val = carry
        else:
            iterator.next = None
        return l.next
        