# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # O(n), O(1), recursion
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


#     O(n), O(n), stack
#     def isPalindrome(self, head: Optional[ListNode]) -> bool:
#         stack = []
#         while head:
#             stack.append(head.val)
#             head = head.next
            
#         l, r = 0, len(stack) - 1
#         while l < r:
#             if stack[l] != stack[r]:
#                 return False
            
#             l += 1
#             r -= 1
            
#         return True