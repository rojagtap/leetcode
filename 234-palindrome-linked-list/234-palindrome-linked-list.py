# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        self.slow = head
        return self.recurse(head)
        
    def recurse(self, fast):
        if not fast.next:
            val = self.slow.val
            self.slow = self.slow.next
            return val == fast.val
        
        val = self.recurse(fast.next) and self.slow.val == fast.val
        self.slow = self.slow.next
        
        return val