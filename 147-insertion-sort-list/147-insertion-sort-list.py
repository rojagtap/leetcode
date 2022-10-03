# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # O(n2), O(1)
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def remove(ptr, prev):
            prev.next = ptr.next
            return prev.next
        
        def insert(ptr, curr):
            ptr.next = curr.next
            curr.next = ptr
            
        prev = head
        ptr = head.next if head else None
        
        while ptr:
            curr = head
            
            if ptr.val <= head.val:
                next = remove(ptr, prev)
                ptr.next = head
                head = ptr
                ptr = next
                continue
            else:
                while curr.next != ptr and curr.next.val < ptr.val:
                    curr = curr.next
                
                if curr.next != ptr:
                    next = remove(ptr, prev)
                    insert(ptr, curr)
                    ptr = next
                    continue
                    
            prev = ptr
            ptr = ptr.next
            
        return head
            