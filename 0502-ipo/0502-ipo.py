class Solution:
    # O(n + klogn), O(n)
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        capitals_heap = []
        profits_heap = []
        
        for i, money in enumerate(capital):
            heappush(capitals_heap, (money, i))
            
        while k:
            while capitals_heap and capitals_heap[0][0] <= w:
                top = heappop(capitals_heap)
                heappush(profits_heap, (-profits[top[1]], top[1]))
                
            if not profits_heap:
                break
                
            w += -heappop(profits_heap)[0]
            k -= 1
            
        return w