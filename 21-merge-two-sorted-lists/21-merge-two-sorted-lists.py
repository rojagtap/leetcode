# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        l3 = ListNode()
        ptr = l3
        while l1 and l2:
            if l1.val < l2.val:
                ptr.next = ListNode(val=l1.val)
                l1 = l1.next
            else:
                ptr.next = ListNode(val=l2.val)
                l2 = l2.next
            ptr = ptr.next
            
            
        while l1:
            ptr.next = ListNode(val=l1.val)
            ptr = ptr.next
            l1 = l1.next
            
        while l2:
            ptr.next = ListNode(val=l2.val)
            ptr = ptr.next
            l2 = l2.next
            
        return l3.next