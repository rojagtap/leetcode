# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Node:
    def __init__(self, node=None):
        self.node = node
        
    def __lt__(self, other):
        if not self.node:
            return other.node
        if not other.node:
            return self.node
        
        return self.node.val < other.node.val

    
class Solution:
    # O(nk), O(k)
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        head, tail = None, None
        
        heap = []
        for node in lists:
            if node:
                heappush(heap, Node(node))
            
        while heap:
            smallest = heappop(heap).node
            
            if smallest.next:
                heappush(heap, Node(smallest.next))
            
            if head:
                tail.next = smallest
                smallest.next = None
                tail = smallest
            else:
                head = smallest
                tail = smallest
            
        return head
