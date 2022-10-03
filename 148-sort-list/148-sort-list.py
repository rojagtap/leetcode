# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # O(nlogn), O(1)
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
            
        mid = self.mid(head)
        right = mid.next
        mid.next = None
        
        left = self.sortList(head)
        right = self.sortList(right)
        return self.merge(left, right)
        
    
    def mid(self, head):
        slow = fast = head
        
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            
        return slow
    
    def merge(self, left, right):
        head = None
        merged = None        
        while left and right:
            if left.val < right.val:
                if not merged:
                    merged = left
                    head = merged
                else:
                    merged.next = left
                    merged = merged.next
                    
                left = left.next
            else:
                if not merged:
                    merged = right
                    head = merged
                else:
                    merged.next = right
                    merged = merged.next
                    
                right = right.next
            
            merged.next = None
                    
        if left:
            merged.next = left
        
        if right:
            merged.next = right
            
        
        return head     
                    
                    